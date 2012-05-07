######################################################################
# Automatically generated by qmake (2.01a) dl. de mar� 14 10:18:26 2011
######################################################################


TEMPLATE = app
TARGET =
FORMS += uis/AgentConfigurator.ui
FORMS += uis/RasterConfigurator.ui
FORMS += uis/ColorInterval.ui
FORMS += uis/Configurator3D.ui
FORMS += uis/LoadingProgressBar.ui
DEFINES += TIXML_USE_STL
DEPENDPATH += .
INCLUDEPATH += .
INCLUDEPATH += ../pandora/
INCLUDEPATH += /usr/include/qwt/
INCLUDEPATH += /usr/include/mpich2/ 
INCLUDEPATH += /usr/include/GL/
INCLUDEPATH += /usr/include/qt4/QtOpenGL/
INCLUDEPATH += /usr/include/qt4/
INCLUDEPATH += /usr/include/IL/
INCLUDEPATH += /usr/local/hdf5/include/
# Required when installing qwt-6.0.0 from sources
INCLUDEPATH += /usr/local/qwt-6.0.0/include/

CONFIG += qt

# Required when installing qwt-6.0.0 from sources
LIBS += -L../pandora/ -lpandora -L/usr/local/qwt-6.0.0/lib/ -L/usr/local/hdf5/lib/ -lqwt -lhdf5 -lmpich -lmpi -lGL -lGLU -lQtOpenGL -lIL -ltinyxml

# Input
HEADERS += Display2D.hxx MainWindow.hxx AgentTypeSelection.hxx AgentTraitSelection.hxx DataPlot.hxx GenericStatistics.hxx StepDataPlot.hxx RasterSelection.hxx Display3D.hxx AgentConfigurator.hxx Model3D.hxx Object3D.hxx Material.hxx Loader3DS.hxx ColorSelector.hxx DefaultColorSelector.hxx AgentConfiguration.hxx RasterConfigurator.hxx ColorInterval.hxx RasterConfiguration.cxx Configurator3D.hxx Configuration3D.hxx ProjectConfiguration.hxx LoadSimulationThread.hxx LoadingProgressBar.hxx
SOURCES += main.cxx Display2D.cxx  MainWindow.cxx AgentTypeSelection.cxx AgentTraitSelection.cxx DataPlot.cxx MeanDataPlot.cxx SumDataPlot.cxx  GenericStatistics.cxx StepDataPlot.cxx RasterSelection.cxx Display3D.cxx AgentConfigurator.cxx Model3D.cxx Object3D.cxx Material.cxx Loader3DS.cxx DefaultColorSelector.cxx AgentConfiguration.cxx RasterConfigurator.cxx ColorInterval.cxx RasterConfiguration.cxx Configurator3D.cxx Configuration3D.cxx ProjectConfiguration.cxx LoadSimulationThread.cxx LoadingProgressBar.cxx MpiStubCode.cxx
RESOURCES = cassandra.qrc
