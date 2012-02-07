
#ifndef __StaticRaster_hxx__
#define __StaticRaster_hxx__

#include "Point2D.hxx"
#include <vector>

namespace Engine
{
class World;

//! this class is used to load a static raster map. Values can't be modified, and it won't be serialized each time step (only one time)
class StaticRaster
{
protected:
	std::vector< std::vector<int> >_values;

	int _minValue;
	int _maxValue;
public:
	StaticRaster();
	virtual ~StaticRaster();

	// TODO not squared rasters
	//! changes raster size. Parameter 'size' represents the new dimesions for the raster area.
	virtual void resize( const Point2D<int> & size );
	//! Reads the value in the cell located by parameter "position". Returns -1 if "position" is out of the area of the raster.
	const int & getValue( Point2D<int> position ) const;
	
	//! Returns size of the raster codifying the horizontal and vertical dimensions in a Point2D object. 
	Point2D<int> getSize() const;
	// TODO clear before load
	void loadGDALFile( const std::string & fileName, World & world );
	void loadHDF5File( const std::string & fileName, const std::string & rasterName );

	//! Reads attribute _maxValue.
	const int & getMaxValue() const;
	//! Reads the '_minValue' attribute.
	const int & getMinValue() const;
}; 

} // namespace Engine

#endif // __StaticRaster_hxx__
