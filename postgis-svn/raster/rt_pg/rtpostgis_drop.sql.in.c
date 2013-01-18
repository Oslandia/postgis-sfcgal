-- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
--
-- $Id: rtpostgis_drop.sql.in.c 7884 2011-09-22 15:07:25Z robe $
--
-- PostGIS Raster - Raster Type for PostGIS
-- http://trac.osgeo.org/postgis/wiki/WKTRaster
--
-- Copyright (C) 2011 Regina Obe <lr@pcorp.us>
-- Copyright (C) 2011-2012 Regents of the University of California
--   <bkpark@ucdavis.edu>
--
-- This is free software; you can redistribute and/or modify it under
-- the terms of the GNU General Public Licence. See the COPYING file.
--
-- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
--
-- WARNING: Any change in this file must be evaluated for compatibility.
--
-- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
-- This file will be used to drop obselete functions and other objects.
-- It will be used for both upgrade and uninstall
-- Drop obsolete functions 
-- (which fully obsolete, changed to take default args, or outp params changed) --

-- drop aggregates
DROP AGGREGATE IF EXISTS ST_Union(raster, text, text, text, double precision, text, text, text, double precision, text, text, text, double precision);
DROP AGGREGATE IF EXISTS ST_Union(raster, text, text, text);
DROP AGGREGATE IF EXISTS ST_Union(raster, text, text, text, double precision, text, text, text, double precision);
DROP AGGREGATE IF EXISTS ST_Union(raster, text, text);
DROP AGGREGATE IF EXISTS ST_Union(raster, text, text, text, double precision);
DROP AGGREGATE IF EXISTS ST_Union(raster, text);
DROP AGGREGATE IF EXISTS ST_Union(raster, integer);
DROP AGGREGATE IF EXISTS ST_Union(raster, unionarg[]);
DROP AGGREGATE IF EXISTS ST_Union(raster, record[]);
DROP AGGREGATE IF EXISTS ST_Union(raster);

DROP AGGREGATE IF EXISTS st_samealignment(raster);

DROP FUNCTION IF EXISTS ST_Intersects(raster,boolean,geometry);
DROP FUNCTION IF EXISTS ST_Intersects(geometry,raster,boolean);
DROP FUNCTION IF EXISTS ST_Intersects(raster,geometry);
DROP FUNCTION IF EXISTS ST_Intersects(geometry,raster);
DROP FUNCTION IF EXISTS ST_Intersects(raster, integer, boolean  , geometry);
DROP FUNCTION IF EXISTS ST_Intersects(geometry , raster, integer , boolean);
DROP FUNCTION IF EXISTS ST_Intersection(raster,raster, integer, integer);
DROP FUNCTION IF EXISTS ST_Intersection(geometry,raster);
DROP FUNCTION IF EXISTS ST_Intersection(raster, geometry);
DROP FUNCTION IF EXISTS ST_Intersection(raster, integer, geometry);

--these were renamed to ST_MapAlgebraExpr or argument names changed --
DROP FUNCTION IF EXISTS ST_MapAlgebra(raster, integer, text, text, nodatavaluerepl text);
DROP FUNCTION IF EXISTS ST_MapAlgebra(raster, pixeltype text, expression text, nodatavaluerepl text);


--signatures or arg names changed
DROP FUNCTION IF EXISTS ST_MapAlgebraExpr(raster, integer, text, text, text);
DROP FUNCTION IF EXISTS ST_MapAlgebraExpr(raster, text, text, text);
DROP FUNCTION IF EXISTS ST_MapalgebraFct(raster, regprocedure);
DROP FUNCTION IF EXISTS ST_MapAlgebraFct(raster, text, regprocedure, VARIADIC text[]); 
DROP FUNCTION IF EXISTS ST_MapAlgebraFct(raster, text, regprocedure); 
DROP FUNCTION IF EXISTS ST_MapAlgebraFct(raster, regprocedure, VARIADIC text[]);
DROP FUNCTION IF EXISTS ST_MapAlgebraFct(raster, integer, regprocedure, variadic text[]);
DROP FUNCTION IF EXISTS ST_MapAlgebraFct(raster, integer, text, regprocedure, VARIADIC text[]); 
DROP FUNCTION IF EXISTS ST_MapAlgebraFct(raster, integer, text, regprocedure); 
DROP FUNCTION IF EXISTS ST_MapAlgebraFct(raster, integer, regprocedure, variadic text[]);
DROP FUNCTION IF EXISTS ST_MapalgebraFct(raster, integer, regprocedure);
DROP FUNCTION IF EXISTS ST_MapAlgebraFct(raster, raster, regprocedure, text, text, VARIADIC text[]);
DROP FUNCTION IF EXISTS ST_MapAlgebraFct(raster, integer, raster, integer, regprocedure, text, text, VARIADIC text[]);
DROP FUNCTION IF EXISTS ST_MapAlgebraFctNgb(raster, integer, text, integer, integer, regprocedure, text,  VARIADIC text[]);


--dropped functions
DROP FUNCTION IF EXISTS  ST_MapAlgebraFct(raster, raster, regprocedure, VARIADIC text[]);

--added extra parameter so these are obsolete --
DROP FUNCTION IF EXISTS ST_AsRaster(geometry , integer , integer , double precision , double precision , text , double precision , double precision , double precision , double precision );
DROP FUNCTION IF EXISTS ST_AsRaster(geometry , integer , integer , text[] , double precision[] , double precision[] , double precision , double precision , double precision , double precision );
DROP FUNCTION IF EXISTS ST_AsRaster(geometry , integer , integer , text , double precision , double precision , double precision , double precision , double precision , double precision );
DROP FUNCTION IF EXISTS ST_AsRaster(geometry , integer , integer , double precision , double precision , text[] , double precision[] , double precision[] , double precision , double precision );
DROP FUNCTION IF EXISTS ST_AsRaster(geometry , integer , integer , double precision , double precision , text[] , double precision[] , double precision[] , double precision , double precision );
DROP FUNCTION IF EXISTS ST_AsRaster(geometry , double precision , double precision , text , double precision , double precision , double precision , double precision , double precision , double precision );
DROP FUNCTION IF EXISTS ST_AsRaster(geometry , raster , text , double precision , double precision );
DROP FUNCTION IF EXISTS _ST_AsRaster(geometry,double precision , double precision, integer , integer,text[] , double precision[] ,double precision[] ,  double precision,  double precision, double precision,double precision, double precision, double precision,touched boolean);
-- arg names changed
DROP FUNCTION IF EXISTS _ST_Resample(raster, text, double precision, integer, double precision, double precision, double precision, double precision, double precision, double precision);

-- signature changed
DROP FUNCTION IF EXISTS ST_Resample(raster, raster, text, double precision);

-- default parameters added
DROP FUNCTION IF EXISTS ST_HasNoBand(raster);

--function out parameters changed so can not just create or replace
DROP FUNCTION IF EXISTS ST_BandMetaData(raster, integer);

--function out parameter changed
DROP FUNCTION IF EXISTS ST_BandNoDataValue(raster, integer);
--function no longer exists
DROP FUNCTION IF EXISTS ST_BandNoDataValue(raster);

--function no longer exists
DROP FUNCTION IF EXISTS ST_SetGeoReference(raster, text);
-- signature changed
DROP FUNCTION IF EXISTS ST_SetGeoReference(raster, text, text);

--function no longer exists
DROP FUNCTION IF EXISTS st_setbandisnodata(raster);
-- signature changed
DROP FUNCTION IF EXISTS st_setbandisnodata(raster, integer);

--function no longer exists
DROP FUNCTION IF EXISTS st_setbandnodatavalue(raster, integer, double precision);
-- signature changed
DROP FUNCTION IF EXISTS st_setbandnodatavalue(raster, integer, double precision, boolean);

--function no longer exists
DROP FUNCTION IF EXISTS st_dumpaspolygons(raster);
-- signature changed
DROP FUNCTION IF EXISTS st_dumpaspolygons(raster, integer);

--function no longer exists
DROP FUNCTION IF EXISTS st_polygon(raster);
-- signature changed
DROP FUNCTION IF EXISTS st_polygon(raster, integer);

-- function no longer exists
DROP FUNCTION IF EXISTS st_makeemptyraster(int, int, float8, float8, float8, float8, float8, float8);
-- signature changed
DROP FUNCTION IF EXISTS st_makeemptyraster(int, int, float8, float8, float8, float8, float8, float8, int4);

-- function no longer exists
DROP FUNCTION IF EXISTS st_addband(raster, text);
DROP FUNCTION IF EXISTS st_addband(raster, text, float8);
DROP FUNCTION IF EXISTS st_addband(raster, int, text);
DROP FUNCTION IF EXISTS st_addband(raster, int, text, float8);
DROP FUNCTION IF EXISTS st_addband(raster, raster, int);
DROP FUNCTION IF EXISTS st_addband(raster, raster);
-- signature changed
DROP FUNCTION IF EXISTS st_addband(raster, text, float8, float8);
DROP FUNCTION IF EXISTS st_addband(raster, int, text, float8, float8);
DROP FUNCTION IF EXISTS st_addband(raster, raster, int, int);

-- function no longer exists
DROP FUNCTION IF EXISTS st_bandisnodata(raster);
DROP FUNCTION IF EXISTS st_bandisnodata(raster, integer);
-- signature changed
DROP FUNCTION IF EXISTS st_bandisnodata(raster, integer, boolean);

-- function no longer exists
DROP FUNCTION IF EXISTS st_bandpath(raster);
-- signature changed
DROP FUNCTION IF EXISTS st_bandpath(raster, integer);

-- function no longer exists
DROP FUNCTION IF EXISTS st_bandpixeltype(raster);
-- signature changed
DROP FUNCTION IF EXISTS st_bandpixeltype(raster, integer);


-- signature changed and some functions dropped --
-- Note: I am only including the surviving variants 
-- since some people may be using the dead ones which are in scripts 
-- and we do not have a replace for those
DROP AGGREGATE IF EXISTS ST_Union(raster);
DROP AGGREGATE IF EXISTS ST_Union(raster, integer, text); 

-- function no longer exists
DROP FUNCTION IF EXISTS st_value(raster, integer, integer, integer);
DROP FUNCTION IF EXISTS st_value(raster, integer, integer);
DROP FUNCTION IF EXISTS st_value(raster, integer, geometry);
DROP FUNCTION IF EXISTS st_value(raster, geometry);
-- signature changed
DROP FUNCTION IF EXISTS st_value(raster, integer, integer, integer, boolean);
DROP FUNCTION IF EXISTS st_value(raster, integer, integer, boolean);
DROP FUNCTION IF EXISTS st_value(raster, integer, geometry, boolean);
DROP FUNCTION IF EXISTS st_value(raster, geometry, boolean);
DROP FUNCTION IF EXISTS st_value(raster, integer, geometry, double precision);
DROP FUNCTION IF EXISTS st_value(raster, geometry, double precision);

-- function no longer exists
DROP FUNCTION IF EXISTS st_georeference(raster);
-- signature changed
DROP FUNCTION IF EXISTS st_georeference(raster, text);

-- function name change
DROP FUNCTION IF EXISTS dumpaswktpolygons(raster, integer);

-- signature changed
DROP FUNCTION IF EXISTS st_bandmetadata(raster, VARIADIC int[]);

--change to use default parameters
DROP FUNCTION IF EXISTS ST_PixelAsPolygons(raster); 
DROP FUNCTION IF EXISTS ST_PixelAsPolygons(raster,integer);

-- remove TYPE summarystats
DROP FUNCTION IF EXISTS st_summarystats(raster,int, boolean);
DROP FUNCTION IF EXISTS st_summarystats(raster, boolean);
DROP FUNCTION IF EXISTS st_approxsummarystats(raster,int, boolean, double precision);
DROP FUNCTION IF EXISTS st_approxsummarystats(raster,int, double precision);
DROP FUNCTION IF EXISTS st_approxsummarystats(raster, boolean, double precision);
DROP FUNCTION IF EXISTS st_approxsummarystats(raster, double precision);
DROP FUNCTION IF EXISTS st_summarystats(text, text,integer, boolean);
DROP FUNCTION IF EXISTS st_summarystats(text, text, boolean);
DROP FUNCTION IF EXISTS st_approxsummarystats(text, text,integer, boolean, double precision);
DROP FUNCTION IF EXISTS st_approxsummarystats(text, text,integer, double precision);
DROP FUNCTION IF EXISTS st_approxsummarystats(text, text, boolean);
DROP FUNCTION IF EXISTS st_approxsummarystats(text, text, double precision);
DROP FUNCTION IF EXISTS _st_summarystats(raster,int, boolean, double precision);
DROP FUNCTION IF EXISTS _st_summarystats(text, text,integer, boolean, double precision);
DROP TYPE IF EXISTS summarystats;

-- remove TYPE quantile
DROP FUNCTION IF EXISTS st_quantile(raster, int, boolean, double precision[]);
DROP FUNCTION IF EXISTS st_quantile(raster, int, double precision[]);
DROP FUNCTION IF EXISTS st_quantile(raster, double precision[]);
DROP FUNCTION IF EXISTS st_approxquantile(raster, int, boolean, double precision, double precision[]);
DROP FUNCTION IF EXISTS st_approxquantile(raster, int, double precision, double precision[]);
DROP FUNCTION IF EXISTS st_approxquantile(raster, double precision, double precision[]);
DROP FUNCTION IF EXISTS st_approxquantile(raster, double precision[]);
DROP FUNCTION IF EXISTS st_quantile(text, text, int, boolean, double precision[]);
DROP FUNCTION IF EXISTS st_quantile(text, text, int, double precision[]);
DROP FUNCTION IF EXISTS st_quantile(text, text, double precision[]);
DROP FUNCTION IF EXISTS st_approxquantile(text, text, int, boolean, double precision, double precision[]);
DROP FUNCTION IF EXISTS st_approxquantile(text, text, int, double precision, double precision[]);
DROP FUNCTION IF EXISTS st_approxquantile(text, text, double precision, double precision[]);
DROP FUNCTION IF EXISTS st_approxquantile(text, text, double precision[]);
DROP FUNCTION IF EXISTS _st_quantile(raster, int, boolean, double precision, double precision[]);
DROP FUNCTION IF EXISTS _st_quantile(text, text, int, boolean, double precision, double precision[]);
DROP TYPE IF EXISTS quantile;

-- remove TYPE valuecount
DROP FUNCTION IF EXISTS st_valuecount(text, text, integer, double precision, double precision);
DROP FUNCTION IF EXISTS st_valuecount(text, text, integer, boolean, double precision[], double precision);
DROP FUNCTION IF EXISTS st_valuecount(text, text, double precision[], double precision);
DROP FUNCTION IF EXISTS st_valuecount(text, text, integer, double precision[], double precision);
DROP FUNCTION IF EXISTS st_valuecount(text, text, integer, boolean, double precision, double precision);
DROP FUNCTION IF EXISTS st_valuecount(text, text, double precision, double precision);
DROP FUNCTION IF EXISTS st_valuecount(raster, integer, boolean, double precision[], double precision);
DROP FUNCTION IF EXISTS st_valuecount(raster, integer, double precision[], double precision);
DROP FUNCTION IF EXISTS st_valuecount(raster, double precision[], double precision);
DROP FUNCTION IF EXISTS _st_valuecount(text, text, integer, boolean, double precision[], double precision);
DROP FUNCTION IF EXISTS _st_valuecount(raster, integer, boolean, double precision[], double precision);
DROP TYPE IF EXISTS valuecount;

-- remove TYPE histogram
DROP FUNCTION IF EXISTS st_histogram(raster, int, boolean, int, double precision[], boolean);
DROP FUNCTION IF EXISTS st_histogram(raster, int, boolean, int, boolean);
DROP FUNCTION IF EXISTS st_histogram(raster, int, int, double precision[], boolean);
DROP FUNCTION IF EXISTS st_histogram(raster, int, int, boolean);
DROP FUNCTION IF EXISTS st_approxhistogram( raster, int, boolean, double precision, int, double precision[], boolean);
DROP FUNCTION IF EXISTS st_approxhistogram(raster, int, boolean, double precision, int, boolean);
DROP FUNCTION IF EXISTS st_approxhistogram(raster, int, double precision);
DROP FUNCTION IF EXISTS st_approxhistogram(raster, double precision);
DROP FUNCTION IF EXISTS st_approxhistogram(raster, int, double precision, int, double precision[], boolean);
DROP FUNCTION IF EXISTS st_approxhistogram(raster, int, double precision, int, boolean);
DROP FUNCTION IF EXISTS st_histogram(text, text, int, boolean, int, double precision[], boolean);
DROP FUNCTION IF EXISTS st_histogram(text, text, int, boolean, int, boolean);
DROP FUNCTION IF EXISTS st_histogram(text, text, int, int, double precision[], boolean);
DROP FUNCTION IF EXISTS st_histogram(text, text, int, int, boolean);
DROP FUNCTION IF EXISTS st_approxhistogram( text, text, int, boolean, double precision, int, double precision[], boolean);
DROP FUNCTION IF EXISTS st_approxhistogram(text, text, int, boolean, double precision, int, boolean);
DROP FUNCTION IF EXISTS st_approxhistogram(text, text, int, double precision);
DROP FUNCTION IF EXISTS st_approxhistogram(text, text, double precision);
DROP FUNCTION IF EXISTS st_approxhistogram(text, text, int, double precision, int, double precision[], boolean);
DROP FUNCTION IF EXISTS st_approxhistogram(text, text, int, double precision, int, boolean);
DROP FUNCTION IF EXISTS _st_histogram( raster, int, boolean, double precision, int, double precision[], boolean, double precision, double precision);
DROP FUNCTION IF EXISTS _st_histogram( text, text, int, boolean, double precision, int, double precision[], boolean);
DROP TYPE IF EXISTS histogram;

-- no longer needed functions changed to use out parameters
DROP TYPE IF EXISTS bandmetadata;
DROP TYPE IF EXISTS geomvalxy;

-- raster_columns and raster_overviews tables are deprecated
DROP FUNCTION IF EXISTS _rename_raster_tables();
CREATE OR REPLACE FUNCTION _rename_raster_tables()
	RETURNS void AS $$
	DECLARE
		cnt int;
	BEGIN
		SELECT count(*) INTO cnt
		FROM pg_class c
		JOIN pg_namespace n
			ON c.relnamespace = n.oid
		WHERE c.relname = 'raster_columns'
			AND c.relkind = 'r'::char
			AND NOT pg_is_other_temp_schema(c.relnamespace);

		IF cnt > 0 THEN
			EXECUTE 'ALTER TABLE raster_columns RENAME TO deprecated_raster_columns';
		END IF;

		SELECT count(*) INTO cnt
		FROM pg_class c
		JOIN pg_namespace n
			ON c.relnamespace = n.oid
		WHERE c.relname = 'raster_overviews'
			AND c.relkind = 'r'::char
			AND NOT pg_is_other_temp_schema(c.relnamespace);

		IF cnt > 0 THEN
			EXECUTE 'ALTER TABLE raster_overviews RENAME TO deprecated_raster_overviews';
		END IF;

	END;
	$$ LANGUAGE 'plpgsql' VOLATILE;
SELECT _rename_raster_tables();
DROP FUNCTION _rename_raster_tables();

-- inserted new column into view
DROP VIEW IF EXISTS raster_columns;

-- functions no longer supported
DROP FUNCTION IF EXISTS AddRasterColumn(varchar, varchar, varchar, varchar, integer, varchar[], boolean, boolean, double precision[], double precision, double precision, integer, integer, geometry);
DROP FUNCTION IF EXISTS AddRasterColumn(varchar, varchar, varchar, integer, varchar[], boolean, boolean, double precision[], double precision, double precision, integer, integer, geometry);
DROP FUNCTION IF EXISTS AddRasterColumn(varchar, varchar, integer, varchar[], boolean, boolean, double precision[], double precision, double precision, integer, integer, geometry);
DROP FUNCTION IF EXISTS DropRasterColumn(varchar, varchar, varchar, varchar);
DROP FUNCTION IF EXISTS DropRasterColumn(varchar, varchar, varchar);
DROP FUNCTION IF EXISTS DropRasterColumn(varchar, varchar);
DROP FUNCTION IF EXISTS DropRasterTable(varchar, varchar, varchar);
DROP FUNCTION IF EXISTS DropRasterTable(varchar, varchar);
DROP FUNCTION IF EXISTS DropRasterTable(varchar);

-- function parameters added
DROP FUNCTION IF EXISTS AddRasterConstraints(name, name, name, boolean, boolean, boolean, boolean, boolean, boolean, boolean, boolean, boolean, boolean, boolean);
DROP FUNCTION IF EXISTS AddRasterConstraints(name, name, boolean, boolean, boolean, boolean, boolean, boolean, boolean, boolean, boolean, boolean, boolean);
DROP FUNCTION IF EXISTS DropRasterConstraints(name, name, name, boolean, boolean, boolean, boolean, boolean, boolean, boolean, boolean, boolean, boolean, boolean);
DROP FUNCTION IF EXISTS DropRasterConstraints(name, name, boolean, boolean, boolean, boolean, boolean, boolean, boolean, boolean, boolean, boolean, boolean);

-- function parameters renamed
CREATE OR REPLACE FUNCTION _drop_st_samealignment()
	RETURNS void AS $$
	DECLARE
		cnt int;
	BEGIN
		SELECT count(*) INTO cnt
		FROM pg_proc
		WHERE lower(proname) = 'st_samealignment'
			AND pronargs = 2
			AND (
				proargnames = '{rasta,rastb}'::text[] OR
				proargnames = '{rastA,rastB}'::text[]
			);

		IF cnt > 0 THEN
			RAISE NOTICE 'Dropping ST_SameAlignment(raster, raster) due to parameter name changes.  Unfortunately, this is a DROP ... CASCADE as the alignment raster constraint uses ST_SameAlignment(raster, raster).  You will need to reapply AddRasterConstraint(''SCHEMA'', ''TABLE'', ''COLUMN'', ''alignment'') to any raster column that requires this constraint.';
			DROP FUNCTION IF EXISTS st_samealignment(raster, raster) CASCADE;
		END IF;
	END;
	$$ LANGUAGE 'plpgsql' VOLATILE;
SELECT _drop_st_samealignment();
DROP FUNCTION _drop_st_samealignment();

DROP FUNCTION IF EXISTS _st_intersects(raster, integer, raster, integer);
DROP FUNCTION IF EXISTS st_intersects(raster, integer, raster, integer);
DROP FUNCTION IF EXISTS st_intersects(raster, raster);

-- functions have changed dramatically
DROP FUNCTION IF EXISTS st_intersection(raster, integer, geometry);
DROP FUNCTION IF EXISTS st_intersection(raster, geometry);

-- function was renamed
DROP FUNCTION IF EXISTS st_minpossibleval(text);

-- function deprecated previously
DROP FUNCTION IF EXISTS st_pixelaspolygon(raster, integer, integer, integer);

-- function signatures changed
DROP FUNCTION IF EXISTS st_intersection(raster, int, geometry, text, regprocedure);
DROP FUNCTION IF EXISTS st_intersection(raster, int, geometry, regprocedure);
DROP FUNCTION IF EXISTS st_intersection(raster, geometry, text, regprocedure);
DROP FUNCTION IF EXISTS st_intersection(raster, geometry, regprocedure);
DROP FUNCTION IF EXISTS st_clip(raster, integer, geometry, boolean);
DROP FUNCTION IF EXISTS st_clip(raster, geometry, float8, boolean);
DROP FUNCTION IF EXISTS st_clip(raster, geometry, boolean);
DROP FUNCTION IF EXISTS st_clip(raster, int, geometry, float8, boolean);
DROP FUNCTION IF EXISTS st_clip(raster, geometry, float8[], boolean);
DROP FUNCTION IF EXISTS st_clip(raster, integer, geometry, float8[], boolean);

-- refactoring of functions
DROP FUNCTION IF EXISTS _st_dumpaswktpolygons(raster, integer);
DROP TYPE IF EXISTS wktgeomval;

-- function parameter names changed
DROP FUNCTION IF EXISTS st_nearestvalue(raster, integer, integer, integer, boolean);
DROP FUNCTION IF EXISTS st_nearestvalue(raster, integer, integer, boolean);
DROP FUNCTION IF EXISTS st_neighborhood(raster, integer, integer, integer, integer, boolean);
DROP FUNCTION IF EXISTS st_neighborhood(raster, integer, integer, integer, boolean);
DROP FUNCTION IF EXISTS st_neighborhood(raster, integer, geometry, integer, boolean);
DROP FUNCTION IF EXISTS st_neighborhood(raster, geometry, integer, boolean);

-- variants of st_intersection with regprocedure no longer exist
DROP FUNCTION IF EXISTS st_intersection(raster, integer, raster, integer, text, regprocedure);
DROP FUNCTION IF EXISTS st_intersection(raster, integer, raster, integer, regprocedure);
DROP FUNCTION IF EXISTS st_intersection(raster, raster, text, regprocedure);
DROP FUNCTION IF EXISTS st_intersection(raster, raster, regprocedure);

-- function deprecated
DROP FUNCTION IF EXISTS st_pixelaspolygons(raster, integer);

-- function deprecated
DROP FUNCTION IF EXISTS st_bandsurface(raster, integer);

-- function no longer exist or refactored
DROP FUNCTION IF EXISTS st_intersects(raster, integer, geometry);
DROP FUNCTION IF EXISTS st_intersects(raster, geometry, integer);
DROP FUNCTION IF EXISTS st_intersects(geometry, raster, integer);
DROP FUNCTION IF EXISTS _st_intersects(raster, geometry, integer);
DROP FUNCTION IF EXISTS _st_intersects(geometry, raster, integer);

-- function no longer exists
DROP FUNCTION IF EXISTS st_overlaps(geometry, raster, integer);
DROP FUNCTION IF EXISTS st_overlaps(raster, integer, geometry);
DROP FUNCTION IF EXISTS st_overlaps(raster, geometry, integer);
DROP FUNCTION IF EXISTS _st_overlaps(raster, geometry, integer);
DROP FUNCTION IF EXISTS _st_overlaps(geometry, raster, integer);

-- function no longer exists
DROP FUNCTION IF EXISTS st_touches(geometry, raster, integer);
DROP FUNCTION IF EXISTS st_touches(raster, geometry, integer);
DROP FUNCTION IF EXISTS st_touches(raster, integer, geometry);
DROP FUNCTION IF EXISTS _st_touches(geometry, raster, integer);
DROP FUNCTION IF EXISTS _st_touches(raster, geometry, integer);

-- function no longer exists
DROP FUNCTION IF EXISTS st_contains(raster, geometry, integer);
DROP FUNCTION IF EXISTS st_contains(raster, integer, geometry);
DROP FUNCTION IF EXISTS st_contains(geometry, raster, integer);
DROP FUNCTION IF EXISTS _st_contains(raster, geometry, integer);
DROP FUNCTION IF EXISTS _st_contains(geometry, raster, integer);

-- function signature changed
DROP FUNCTION IF EXISTS st_addband(raster, raster[], integer);

-- function signatures changed
DROP FUNCTION IF EXISTS st_slope(raster, integer, text, text, double precision, boolean);
DROP FUNCTION IF EXISTS st_slope(raster, integer, text, boolean);
DROP FUNCTION IF EXISTS st_slope(raster, integer, text);
DROP FUNCTION IF EXISTS st_aspect(raster, integer, text, text, boolean);
DROP FUNCTION IF EXISTS st_aspect(raster, integer, text, boolean);
DROP FUNCTION IF EXISTS st_aspect(raster, integer, text);
DROP FUNCTION IF EXISTS st_hillshade(raster, integer, text, double precision, double precision, double precision, double precision, boolean);
DROP FUNCTION IF EXISTS st_hillshade(raster, integer, text, float, float, float, float, boolean);
DROP FUNCTION IF EXISTS st_hillshade(raster, integer, text, float, float, float, float);

-- function no longer exists
DROP FUNCTION IF EXISTS st_tile(raster, integer, integer, integer[]);
DROP FUNCTION IF EXISTS st_tile(raster, integer, integer, integer);

-- function signatures changed
DROP FUNCTION IF EXISTS st_setvalue(raster, integer, geometry, double precision);
DROP FUNCTION IF EXISTS st_setvalue(raster, geometry, double precision);

-- function name change
DROP FUNCTION IF EXISTS st_world2rastercoord(raster, double precision, double precision);
DROP FUNCTION IF EXISTS st_world2rastercoord(raster, geometry);
DROP FUNCTION IF EXISTS _st_world2rastercoord(raster, double precision, double precision);
DROP FUNCTION IF EXISTS st_world2rastercoordx(raster, float8, float8);
DROP FUNCTION IF EXISTS st_world2rastercoordx(raster, float8);
DROP FUNCTION IF EXISTS st_world2rastercoordx(raster, geometry);
DROP FUNCTION IF EXISTS st_world2rastercoordy(raster, float8, float8);
DROP FUNCTION IF EXISTS st_world2rastercoordy(raster, float8);
DROP FUNCTION IF EXISTS st_world2rastercoordy(raster, geometry);
DROP FUNCTION IF EXISTS st_raster2worldcoord( raster, integer, integer);
DROP FUNCTION IF EXISTS _st_raster2worldcoord(raster, integer, integer);
DROP FUNCTION IF EXISTS st_raster2worldcoordx(raster, int, int);
DROP FUNCTION IF EXISTS st_raster2worldcoordx(raster, int);
DROP FUNCTION IF EXISTS st_raster2worldcoordy(raster, int, int);
DROP FUNCTION IF EXISTS st_raster2worldcoordy(raster, int);

-- function name change
DROP FUNCTION IF EXISTS _st_resample(raster, text, double precision, integer, double precision, double precision, double precision, double precision, double precision, double precision, integer, integer);

-- function signatures changed
DROP FUNCTION IF EXISTS st_resample(raster, integer, double precision, double precision, double precision, double precision, double precision, double precision, text, double precision);
DROP FUNCTION IF EXISTS st_resample(raster, integer, integer, integer, double precision, double precision, double precision, double precision, text, double precision);

-- function signatures changed
DROP FUNCTION IF EXISTS _st_tile(raster, integer, integer, int[]);
DROP FUNCTION IF EXISTS st_tile(raster, integer[], integer, integer);
DROP FUNCTION IF EXISTS st_tile(raster, integer, integer, integer);
DROP FUNCTION IF EXISTS st_tile(raster, integer, integer);

-- function no longer exists
DROP FUNCTION IF EXISTS _add_raster_constraint_regular_blocking(name, name, name);
