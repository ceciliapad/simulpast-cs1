
#include "StaticRaster.hxx"
#include "Exceptions.hxx"
#include "World.hxx"

namespace Engine
{

StaticRaster::StaticRaster() : _maxValue(std::numeric_limits<int>::min()), _minValue(std::numeric_limits<int>::max())								   
{
}

StaticRaster::~StaticRaster()
{
}

void StaticRaster::resize( const Point2D<int> & size )
{
	_values.resize(size._x);
	// TODO explore how to improve performance with STL algorithms
	// for_each(_valuesField.begin(),_valuesField.end(),resize(_matrixSize));
	for(int i=0; i<size._x; i++)
	{
		_values[i].resize(size._y);
	}
}

void StaticRaster::setDefaultInitValues( int minValue, int maxValue, int defaultValue )
{
	_minValue = minValue;
	_maxValue = maxValue;
	for(int i=0; i<_values.size(); i++)
	{
		for(int j=0; j<_values[i].size(); j++)
		{		
			setInitValue(Point2D<int>(i,j), defaultValue);			
		}
	}
}

const int & StaticRaster::getValue( Point2D<int> position ) const
{
	if(position._x<0 || position._x>=_values.size())
	{
		std::stringstream oss;
		oss << "StaticRaster::getValue - " << position << " x out of bounds: " << _values.size();
		throw Exception(oss.str());
		return -1;
	}
	if(position._y<0 || position._y>=_values[position._x].size())
	{
		std::stringstream oss;
		oss << "StaticRaster::getValue - " << position << " y out of bounds: " << _values.size() << "/" << _values[position._x].size();
		throw Exception(oss.str());
		return -1;
	}
	return _values[position._x][position._y];
}

void StaticRaster::setInitValue( Point2D<int> position, int value )
{
	if(value>_maxValue)
	{
		std::stringstream oss;
		oss << "Raster::setInitValue - value: " << value << " bigger than max value: " << _maxValue << " at position: " << position;
		throw Exception(oss.str());

		return;
	}
	if(position._x<0 || position._x>=_values.size())
	{
		std::stringstream oss;
		oss << "Raster::setInitValue - " << position << " x out of bounds: " << _values.size();
		throw Exception(oss.str());

		return;
	}
	if(position._y<0 || position._y>=_values[position._x].size())
	{
		std::stringstream oss;
		oss << "Raster::setInitValue - " << position << " y out of bounds: " << _values.size() << "/" << _values[position._x].size();
		throw Exception(oss.str());
		return;
	}
	_values[position._x][position._y] = value;
}

Point2D<int> StaticRaster::getSize() const
{
	if(_values.size()==0)
	{
		return Point2D<int>(0,0);
	}
	return Point2D<int>(_values.size(), _values[0].size());
}

const int & StaticRaster::getMinValue() const
{
	return _minValue;
}

const int & StaticRaster::getMaxValue() const
{
	return _maxValue;
}

float StaticRaster::getAvgValue() const
{
	if(_values.size()==0) 
	{
		return 0.0f;
	}
	float norm = 0.0f;
	float avg = 0.0f;

	for(int i=0; i<_values.size(); i++)
	{
		for(int j=0; j<_values[i].size(); j++)
		{		
			norm += 1.0;
			avg += _values[i][j];
		}
	}
	return avg / norm;
}

void StaticRaster::updateMinMaxValues()
{
	_minValue = std::numeric_limits<int>::max();
	_maxValue = std::numeric_limits<int>::min();
	for(int i=0; i<_values.size(); i++)
	{
		for(int j=0; j<_values[i].size(); j++)
		{
			_minValue = std::min(_minValue, _values[i][j]);
			_maxValue = std::max(_maxValue, _values[i][j]);
		}
	}
}

} // namespace Engine

