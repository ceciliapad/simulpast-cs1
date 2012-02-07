
#include "StepDataPlot.hxx"

#include "SimulationRecord.hxx"
#include "Exceptions.hxx"
#include "AgentRecord.hxx"

#include <qwt_legend.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_marker.h>
#include <qwt_plot_zoomer.h>
#include <qwt_plot_panner.h>
#include <qwt_plot_picker.h>

#include <iostream>
#include <sstream>
#include <limits>

namespace GUI
{

StepDataPlot::StepDataPlot( QWidget * parent ) : QwtPlot(parent), _valuePlot(0), _zoomer(0), _simulationRecord(0), _values(0,0), _numSamples(0,0), _minValue(0), _maxValue(0), _type("unknown"), _state("unknown"), _step(0)
{
	// Set axis titles
	setAxisTitle(xBottom, "value");
	setAxisTitle(yLeft, "number of samples");
  
	_valuePlot = new QwtPlotCurve();
	_valuePlot->setStyle(QwtPlotCurve::Lines);
	_valuePlot->setPen(QPen(Qt::red));
	_valuePlot->attach(this);	

	_zoomer = new QwtPlotZoomer(canvas());   
	_zoomer->setMousePattern(QwtEventPattern::MouseSelect2, Qt::RightButton, Qt::ControlModifier);
    _zoomer->setMousePattern(QwtEventPattern::MouseSelect3, Qt::RightButton);

	//_zoomer->setRubberBandPen(QPen(Qt::black, 1, Qt::DotLine));
	//_zoomer->setTrackerPen(QPen(Qt::red));
	_zoomer->setTrackerMode(QwtPlotZoomer::AlwaysOn);
	//_zoomer->setRubberBand(QwtPlotZoomer::VLineRubberBand);

	QwtPlotPanner *panner = new QwtPlotPanner(canvas());
	panner->setMouseButton(Qt::MidButton);

	/*
	QwtPlotPicker * d_picker = new QwtPlotPicker(QwtPlot::xBottom, QwtPlot::yLeft,
        QwtPicker::NoSelection, 
        QwtPlotPicker::CrossRubberBand, QwtPicker::AlwaysOn, 
        canvas());
    d_picker->setRubberBandPen(QColor(Qt::green));
    d_picker->setRubberBand(QwtPicker::CrossRubberBand);
    d_picker->setTrackerPen(QColor(Qt::white));

	connect(d_picker, SIGNAL(moved(const QPoint &)), SLOT(mouseMoved(const QPoint &)));
	*/
	replot();
}

StepDataPlot::~StepDataPlot()
{
}

void StepDataPlot::setSimulationRecord( Engine::SimulationRecord * simulationRecord )
{
	_simulationRecord = simulationRecord;

	if(!_simulationRecord)
	{
		return;
	}
	_values.clear();
	_numSamples.clear();
	replot();
	_zoomer->setZoomBase();
}

void StepDataPlot::stateSelected( const std::string & type, const std::string & state )
{
	_type = type;
	_state = state;
	updateData();
}

void StepDataPlot::stepChanged(int step )
{
	if(_state=="unknown" || _state=="unknown")
	{
		return;
	}
	_step = step/_simulationRecord->getResolution();
	updateData();
}

void StepDataPlot::fillHistogram( const std::string & type, const std::string & state, int step, QVector<double> & numSamples, const int & minValue )
{	
	for(Engine::SimulationRecord::AgentRecordsMap::iterator it=_simulationRecord->beginAgents(type); it!=_simulationRecord->endAgents(type); it++)
	{
		Engine::AgentRecord * agentRecord = it->second;	
		bool exists = agentRecord->getState(step, "exists");
		if(exists)
		{
			int agentValue = agentRecord->getState(step, state);
			if(agentValue!=std::numeric_limits<int>::max())
			{
				numSamples[agentValue-minValue]++;
			}
		}
	}
}

void StepDataPlot::fillStepMinMaxValues(  const std::string & type, const std::string & state, int step, int & minValue, int & maxValue )
{
	minValue = std::numeric_limits<double>::max();
	maxValue = 0;

	for(Engine::SimulationRecord::AgentRecordsMap::iterator it=_simulationRecord->beginAgents(type); it!=_simulationRecord->endAgents(type); it++)
	{
		Engine::AgentRecord * agentRecord = it->second;	
		bool exists = agentRecord->getState(step, "exists");
		if(exists)
		{
			int agentValue = agentRecord->getState(step, state);
			if(agentValue<minValue)
			{
				minValue = agentValue;
			}
			if(agentValue>maxValue)
			{
				maxValue = agentValue;
			}
		}
	}
	if(minValue==maxValue)
	{
		minValue--;
		maxValue++;
	}
}

void StepDataPlot::updateData()
{
	_values.clear();
	_numSamples.clear();

	fillStepMinMaxValues(_type, _state, _step, _minValue, _maxValue);
	int difference = _maxValue - _minValue;
	_values.resize(difference+1);
	_numSamples.resize(_values.size());

	fillHistogram(_type, _state, _step, _numSamples, _minValue);

	for(int i=0; i<_values.size(); i++)
	{
		_values[i] = i+_minValue;
	}

	int maxNumberOfSamples = 0;
	for(int i=0; i<_numSamples.size(); i++)
	{
		if(_numSamples[i]>maxNumberOfSamples)
		{
			maxNumberOfSamples = _numSamples[i];
		}
	}
	
	setAxisScale(xBottom, _minValue-1, _maxValue+1);
    setAxisScale(yLeft, 0, maxNumberOfSamples+1);

	//_valuePlot->setRawData(_values.data(), _numSamples.data(), _values.size());
	_valuePlot->setRawSamples(_values.data(), _numSamples.data(), _values.size());
	replot();
	_zoomer->setZoomBase();
}

} // namespace GUI
