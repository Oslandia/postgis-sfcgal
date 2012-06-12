/**********************************************************************
 *
 * PostGIS - Spatial Types for PostgreSQL
 * http://postgis.refractions.net
 *
 *
 * This is free software; you can redistribute and/or modify it under
 * the terms of the GNU General Public Licence. See the COPYING file.
 *
 **********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CUnit/Basic.h"

#include "lwgeom_sfcgal.h"
#include "cu_tester.h"

// TODO: add expected strings, since from_wkt(to_wkt(geom_as_wkt)) is not always == geom_as_wkt
// (triangle and tin for instance)

static void test_sfcgal_noop(void)
{
	int i;

	char *ewkt[] =
	{
		"POINT(0 0.2)",
		"LINESTRING(-1 -1,-1 2.5,2 2,2 -1)",
		"TRIANGLE((0 0,-1 1,0 -1,0 0))",
		"MULTIPOINT(0.9 0.9,0.9 0.9,0.9 0.9,0.9 0.9,0.9 0.9,0.9 0.9)",
		"SRID=1;MULTILINESTRING((-1 -1,-1 2.5,2 2,2 -1),(-1 -1,-1 2.5,2 2,2 -1),(-1 -1,-1 2.5,2 2,2 -1),(-1 -1,-1 2.5,2 2,2 -1))",
		"SRID=1;MULTILINESTRING((-1 -1,-1 2.5,2 2,2 -1),(-1 -1,-1 2.5,2 2,2 -1),(-1 -1,-1 2.5,2 2,2 -1),(-1 -1,-1 2.5,2 2,2 -1))",
		"POLYGON((-1 -1,-1 2.5,2 2,2 -1,-1 -1),(0 0,0 1,1 1,1 0,0 0))",
		"SRID=4326;POLYGON((-1 -1,-1 2.5,2 2,2 -1,-1 -1),(0 0,0 1,1 1,1 0,0 0))",
		"SRID=4326;POLYGON((-1 -1 1,-1 2.5 1,2 2 2,2 -1 2,-1 -1 2),(0 0 1,0 1 1,1 1 1,1 0 2,0 0 2))",
		"SRID=4326;POLYGON((-1 -1,-1 2.5,2 2,2 -1,-1 -1),(0 0,0 1,1 1,1 0,0 0),(-0.5 -0.5,-0.5 -0.4,-0.4 -0.4,-0.4 -0.5,-0.5 -0.5))",
		"SRID=100000;POLYGON((-1 -1 3,-1 2.5 3,2 2 3,2 -1 3,-1 -1 3),(0 0 3,0 1 3,1 1 3,1 0 3,0 0 3),(-0.5 -0.5 3,-0.5 -0.4 3,-0.4 -0.4 3,-0.4 -0.5 3,-0.5 -0.5 3))",
		"SRID=4326;MULTIPOLYGON(((-1 -1,-1 2.5,2 2,2 -1,-1 -1),(0 0,0 1,1 1,1 0,0 0),(-0.5 -0.5,-0.5 -0.4,-0.4 -0.4,-0.4 -0.5,-0.5 -0.5)),((-1 -1,-1 2.5,2 2,2 -1,-1 -1),(0 0,0 1,1 1,1 0,0 0),(-0.5 -0.5,-0.5 -0.4,-0.4 -0.4,-0.4 -0.5,-0.5 -0.5)))",
		"SRID=4326;GEOMETRYCOLLECTION(POINT(0 1),POLYGON((-1 -1,-1 2.5,2 2,2 -1,-1 -1),(0 0,0 1,1 1,1 0,0 0)),MULTIPOLYGON(((-1 -1,-1 2.5,2 2,2 -1,-1 -1),(0 0,0 1,1 1,1 0,0 0),(-0.5 -0.5,-0.5 -0.4,-0.4 -0.4,-0.4 -0.5,-0.5 -0.5))))",
		"POLYHEDRALSURFACE(((-1 -1,-1 2.5,2 2,2 -1,-1 -1),(0 0,0 1,1 1,1 0,0 0),(-0.5 -0.5,-0.5 -0.4,-0.4 -0.4,-0.4 -0.5,-0.5 -0.5)),((-1 -1,-1 2.5,2 2,2 -1,-1 -1),(0 0,0 1,1 1,1 0,0 0),(-0.5 -0.5,-0.5 -0.4,-0.4 -0.4,-0.4 -0.5,-0.5 -0.5)))",
		"POLYHEDRALSURFACE(((-1 -1 1,-1 2.5 1,2 2 1,2 -1 1,-1 -1 1),(0 0 1,0 1 1,1 1 1,1 0 1,0 0 1),(-0.5 -0.5 1,-0.5 -0.4 1,-0.4 -0.4 1,-0.4 -0.5 1,-0.5 -0.5 1)),((-1 -1 1,-1 2.5 1,2 2 1,2 -1 1,-1 -1 1),(0 0 1,0 1 1,1 1 1,1 0 1,0 0 1),(-0.5 -0.5 1,-0.5 -0.4 1,-0.4 -0.4 1,-0.4 -0.5 1,-0.5 -0.5 1)))",
		"TIN(((0 0,0 -1,-1 1,0 0)),((0 0,1 0,0 -1,0 0)))",
	};


	for ( i = 0; i < (sizeof ewkt/sizeof(char *)); i++ )
	{
		LWGEOM *geom_in, *geom_out;
		char *in_ewkt;
		char *out_ewkt;

		in_ewkt = ewkt[i];
		geom_in = lwgeom_from_wkt(in_ewkt, LW_PARSER_CHECK_NONE);
		geom_out = lwgeom_sfcgal_noop(geom_in);
		if ( ! geom_out ) {
			fprintf(stderr, "\nNull return from lwgeom_sfcgal_noop with wkt:   %s\n", in_ewkt);
			lwgeom_free(geom_in);
			continue;
		}
		out_ewkt = lwgeom_to_ewkt(geom_out);
		if (strcmp(in_ewkt, out_ewkt))
			fprintf(stderr, "\nExp:   %s\nObt:  %s\n", in_ewkt, out_ewkt);
		CU_ASSERT_STRING_EQUAL(in_ewkt, out_ewkt);
		lwfree(out_ewkt);
		lwgeom_free(geom_out);
		lwgeom_free(geom_in);
	}
}


/*
** Used by test harness to register the tests in this file.
*/
CU_TestInfo sfcgal_tests[] =
{
	PG_TEST(test_sfcgal_noop),
	CU_TEST_INFO_NULL
};
CU_SuiteInfo sfcgal_suite = {"SFCGAL",  NULL,  NULL, sfcgal_tests};

