#include <SFCGAL/LineString.h>

namespace SFCGAL {

///
///
///
LineString::LineString():
	_points()
{

}

///
///
///
LineString::LineString( const Point & startPoint, const Point & endPoint ):
	_points(2)
{
	_points[0] = startPoint ;
	_points[1] = endPoint ;
}

///
///
///
LineString::LineString( LineString const& other ):
	_points(other._points)
{

}

///
///
///
LineString& LineString::operator = ( const LineString & other )
{
	_points = other._points ;
	return *this ;
}

///
///
///
LineString::~LineString()
{

}

///
///
///
LineString * LineString::clone() const
{
	return new LineString(*this);
}


///
///
///
GeometryType LineString::geometryTypeId() const
{
	return TYPE_LINESTRING ;
}

///
///
///
std::string LineString::geometryType() const
{
	return "LineString" ;
}

///
///
///
int LineString::dimension() const
{
	return 1 ;
}

///
///
///
int   LineString::coordinateDimension() const
{
	return isEmpty() ? 0 : _points[0].coordinateDimension() ;
}

///
///
///
bool   LineString::isEmpty() const
{
	return _points.empty() ;
}

///
///
///
bool  LineString::is3D() const
{
	return ! isEmpty() && startPoint().is3D() ;
}




}//SFCGAL

