
#include "AgentConfiguration.hxx"
#include <sstream>
#include <iostream>
#include "Exceptions.hxx"
#include "Loader3DS.hxx"
#include "Model3D.hxx"

namespace GUI
{

AgentConfiguration::AgentConfiguration() : _color(rand()%256,rand()%256,rand()%256), _icon(0), _useIcon(false), _fileName2D(""), _size(1.0f), _size3D(1.0f, 1.0f, 1.0f), _fileName3D("resources/3dmodels/spaceship.3ds"), _model(0)
{
	// there are 10 icons, from 1 to 10
	int index = 1+rand()%10;
	std::stringstream fileNameStream;
	fileNameStream << "default_agent_" << index << ".png";
	_fileName2D = "~/workspace/SCSim/cassandra/resources/agentIcons/" + fileNameStream.str();
	std::stringstream resourceNameStream;
	resourceNameStream << ":/resources/agentIcons/" << fileNameStream.str();
	_icon = new QIcon(resourceNameStream.str().c_str());
	_model = Loader3DS::instance()->loadModel(_fileName3D);
	_model->setModelScale(_size3D);
}

AgentConfiguration::AgentConfiguration( const AgentConfiguration & prototype ) : _color(prototype.getColor()), _icon(0), _useIcon(prototype.useIcon()), _fileName2D(prototype.getFileName2D()), _size(prototype.getSize()), _size3D(prototype.getSize3D()), _fileName3D(prototype.getFileName3D())
{
	_icon = new QIcon(prototype.getIcon());
	_model = Loader3DS::instance()->loadModel(_fileName3D);
	_model->setModelScale(_size3D);
}

AgentConfiguration::~AgentConfiguration()
{
	if(_icon)
	{
		delete _icon;
	}
	if(_model)
	{
		delete _model;
	}
}

void AgentConfiguration::setColor( const QColor & color )
{
	_color = color;
}

/*
void AgentConfiguration::setIcon( const std::string & fileName )
{
	if(fileName.compare(_fileName2D)==0)
	{
		return;
	}
	delete _icon;
	_icon = new QIcon(fileName.c_str());
}
*/

void AgentConfiguration::setUseIcon( const bool & useIcon )
{
	_useIcon = useIcon;
}

const bool & AgentConfiguration::useIcon() const
{
	return _useIcon;
}

const QColor & AgentConfiguration::getColor() const
{
	return _color;
}

const QIcon & AgentConfiguration::getIcon() const
{
	return *_icon;
}
	
void AgentConfiguration::setSize( const float & size )
{
	_size = size;
}
	
const float & AgentConfiguration::getSize() const
{
	return _size;
}

const Engine::Point3D<float> & AgentConfiguration::getSize3D() const
{
	return _size3D;
}

void AgentConfiguration::setSize3D( const Engine::Point3D<float> & size3D )
{
	_size3D = size3D;
	if(_model)
	{
		_model->setModelScale(_size3D);
	}
}

void AgentConfiguration::setFileName3D( const std::string & fileName3D)
{
	// TODO maybe we should wait for 'accept' in agentconfigurator...
	if(_fileName3D.compare(fileName3D)==0)
	{
		return;
	}
	_fileName3D = fileName3D;
	delete _model;
	_model = Loader3DS::instance()->loadModel(_fileName3D);
}

const std::string & AgentConfiguration::getFileName3D() const
{
	return _fileName3D;
}

void AgentConfiguration::setFileName2D( const std::string & fileName2D)
{
	if(_fileName2D.compare(fileName2D)==0)
	{
		return;
	}
	_fileName2D = fileName2D;	
	delete _icon;
	_icon = new QIcon(_fileName2D.c_str());
}

const std::string & AgentConfiguration::getFileName2D() const
{
	return _fileName2D;
}
	
const Model3D & AgentConfiguration::getModel() const
{
	return *_model;
}

} // namespace GUI

