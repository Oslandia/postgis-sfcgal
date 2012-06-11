#include <SFCGAL/io/WktWriter.h>

#include <SFCGAL/all.h>

#include <exception>
#include <boost/exception/all.hpp>

namespace SFCGAL {
namespace io {

///
///
///
WktWriter::WktWriter( std::ostream & s ):
	_s(s)
{

}

///
///
///
void WktWriter::write( const Geometry& g )
{
	switch( g.geometryTypeId() ){
	case TYPE_POINT:
		write( g.as< Point >() );
		return ;
	case TYPE_LINESTRING:
		write( g.as< LineString >() );
		return ;
	case TYPE_POLYGON:
		write( g.as< Polygon >() );
		return ;
	case TYPE_GEOMETRYCOLLECTION:
		write( g.as< GeometryCollection >() );
		return ;
	case TYPE_MULTIPOINT:
		write( g.as< MultiPoint >() );
		return ;
	case TYPE_MULTILINESTRING:
		write( g.as< MultiLineString >() );
		return ;
	case TYPE_MULTIPOLYGON:
		write( g.as< MultiPolygon >() );
		return ;
	}

	std::ostringstream oss;
	oss << "WktWriter : '" << g.geometryType() << "' is not supported" ;
	BOOST_THROW_EXCEPTION( std::runtime_error( oss.str() ) );
}


///
///
///
void WktWriter::write( const Coordinate & g )
{
	for ( size_t i = 0; i < g.size(); i++ ){
		if ( i != 0 )
			_s << " ";
		_s << g[i] ;
	}
}


///
///
///
void WktWriter::write( const Point & g )
{
	_s << "POINT" ;
	if ( g.isEmpty() ){
		_s << " EMPTY" ;
		return ;
	}
	writeInner( g );
}

///
///
///
void WktWriter::writeInner( const Point & g )
{
	_s << "(";
	write( g.coordinates() );
	_s << ")";
}

///
///
///
void WktWriter::write( const LineString & g )
{
	_s << "LINESTRING" ;
	if ( g.isEmpty() ){
		_s << " EMPTY" ;
		return ;
	}
	writeInner(g);
}

///
///
///
void WktWriter::writeInner( const LineString & g )
{
	_s << "(";
	for ( size_t i = 0; i < g.numPoints(); i++ ){
		if ( i != 0 )
			_s << ",";

		write( g.pointN(i).coordinates() );
	}
	_s << ")";
}


///
///
///
void WktWriter::write( const Polygon & g )
{
	_s << "POLYGON" ;
	if ( g.isEmpty() ){
		_s << " EMPTY" ;
		return ;
	}
	writeInner(g);
}

///
///
///
void WktWriter::writeInner( const Polygon & g )
{
	_s << "(";
	writeInner(g.exteriorRing());
	for ( size_t i = 0; i < g.numInteriorRings(); i++ ){
		_s << ",";
		writeInner( g.interiorRingN(i) );
	}
	_s << ")";
}

///
///
///
void WktWriter::write( const GeometryCollection & g )
{
	_s << "GEOMETRYCOLLECTION" ;
	if ( g.isEmpty() ){
		_s << " EMPTY" ;
		return ;
	}

	_s << "(" ;
	for ( size_t i = 0 ; i < g.numGeometries(); i++ ){
		if ( i != 0 )
			_s << ",";
		write( g.geometryN(i) );
	}
	_s << ")" ;
}

///
///
///
void WktWriter::write( const MultiPoint & g )
{
	_s << "MULTIPOINT" ;
	if ( g.isEmpty() ){
		_s << " EMPTY" ;
		return ;
	}

	_s << "(";
	for ( size_t i = 0; i < g.numGeometries(); i++ ){
		if ( i != 0 )
			_s << "," ;
		writeInner( g.geometryN(i).as< Point >() );
	}
	_s << ")";
}

///
///
///
void WktWriter::write( const MultiLineString & g )
{
	_s << "MULTILINESTRING" ;
	if ( g.isEmpty() ){
		_s << " EMPTY" ;
		return ;
	}

	_s << "(";
	for ( size_t i = 0; i < g.numGeometries(); i++ ){
		if ( i != 0 )
			_s << "," ;
		writeInner( g.geometryN(i).as< LineString >() );
	}
	_s << ")";
}

///
///
///
void WktWriter::write( const MultiPolygon & g )
{
	_s << "MULTIPOLYGON" ;
	if ( g.isEmpty() ){
		_s << " EMPTY" ;
		return ;
	}

	_s << "(";
	for ( size_t i = 0; i < g.numGeometries(); i++ ){
		if ( i != 0 )
			_s << "," ;
		writeInner( g.geometryN(i).as< Polygon >() );
	}
	_s << ")";
}


}//io
}//SFCGAL



