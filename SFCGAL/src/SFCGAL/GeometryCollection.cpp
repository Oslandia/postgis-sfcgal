#include <SFCGAL/GeometryCollection.h>

#include <boost/exception/all.hpp>
#include <exception>



namespace SFCGAL {

///
///
///
GeometryCollection::GeometryCollection():
	_geometries()
{

}

///
///
///
GeometryCollection::GeometryCollection( GeometryCollection const& other )
{
	assign(other);
}

///
///
///
GeometryCollection& GeometryCollection::operator = ( const GeometryCollection & other )
{
	assign(other);
	return *this ;
}

///
///
///
GeometryCollection::~GeometryCollection()
{
	for ( std::vector< Geometry* >::iterator it = _geometries.begin(); it != _geometries.end(); ++it ){
		delete *it ;
		*it = 0 ;
	}
}

///
///
///
GeometryCollection *  GeometryCollection::clone() const
{
	return new GeometryCollection(*this);
}

///
///
///
std::string    GeometryCollection::geometryType() const
{
	return "GeometryCollection";
}

///
///
///
GeometryType   GeometryCollection::geometryTypeId() const
{
	return TYPE_GEOMETRYCOLLECTION ;
}

///
///
///
int  GeometryCollection::dimension() const
{
	int maxDimension = 0 ;
	for ( std::vector< Geometry* >::const_iterator it = _geometries.begin(); it != _geometries.end(); ++it ){
		maxDimension = std::max( maxDimension, (*it)->dimension() );
	}
	return maxDimension ;
}

///
///
///
int   GeometryCollection::coordinateDimension() const
{
	if ( isEmpty() ){
		return 0 ;
	}else{
		return _geometries.front()->coordinateDimension() ;
	}
}

///
///
///
bool   GeometryCollection::isEmpty() const
{
	return _geometries.empty() ;
}

///
///
///
bool   GeometryCollection::is3D() const
{
	return ! isEmpty() && _geometries.front()->is3D() ;
}

///
///
///
void    GeometryCollection::addGeometry( Geometry * geometry )
{
	BOOST_ASSERT( geometry != NULL );
	if ( ! isAllowed(*geometry) ){
		std::ostringstream oss;
		oss << "try a add a '" << geometry->geometryType() << "' in a '" << geometryType() << "'";
		BOOST_THROW_EXCEPTION( std::runtime_error( oss.str() ) );
	}
	_geometries.push_back( geometry );
}

///
///
///
void    GeometryCollection::addGeometry( Geometry const& geometry )
{
	addGeometry( geometry.clone() );
}

///
///
///
bool    GeometryCollection::isAllowed( Geometry const& g )
{
	//GeometryCollection accepts all subtypes
	return true ;
}

///
///
///
void    GeometryCollection::assign( const GeometryCollection & other )
{
	for ( size_t i = 0; i < other.numGeometries(); i++ ){
		_geometries.push_back( other.geometryN(i).clone() );
	}
}

}//SFCGAL

