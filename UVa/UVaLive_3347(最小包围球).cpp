/*
	author: AmazingCaddy
	time: 
*/
#include <cstdio>
#include <complex>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <vector>
#include <map>
using namespace std;

const int maxn = 1004;
const double pi = acos( -1.0 );
const double inf = 1e20;
const double eps = 1e-8;

struct point_type
{
	double x, y, z;
};

int npoint, nouter;
point_type point[ maxn ], outer[ 4 ], res;
double radius, tmp;

inline double dist( point_type p1, point_type p2 )
{
	double dx = p1.x - p2.x, dy = p1.y - p2.y, dz = p1.z - p2.z;
	return ( dx * dx + dy * dy + dz *dz );
}

inline double dot( point_type p1, point_type p2 )
{
	return p1.x * p2.x + p1.y * p2.y + p1.z * p2.z;
}

void ball( )
{
	point_type q[ 3 ];
	double m[ 3 ][ 3 ], sol[ 3 ], L[ 3 ], det;
	int i, j;
	res.x = res.y = res.z = radius = 0;
	switch( nouter )
	{
	case 1:
		res = outer[ 0 ];
		break;
	case 2:
		res.x = ( outer[ 0 ].x + outer[ 1 ].x ) / 2;
		res.y = ( outer[ 0 ].y + outer[ 1 ].y ) / 2;
		res.z = ( outer[ 0 ].z + outer[ 1 ].z ) / 2;
		radius = dist( res, outer[ 0 ] );
		break;
	case 3:
		for( i = 0; i < 2; i++ )
		{
			q[ i ].x = outer[ i + 1 ].x - outer[ 0 ].x;
			q[ i ].y = outer[ i + 1 ].y - outer[ 0 ].y;
			q[ i ].z = outer[ i + 1 ].z - outer[ 0 ].z;
		}
		for( i = 0; i < 2; i++ )
			for( j = 0; j < 2; j++ )
				m[ i ][ j ] = dot( q[ i ], q[ j ] ) * 2;
		for( i = 0; i < 2; i++ )
			sol[ i ] = dot( q[ i ], q[ i ] );
		if( fabs( det = m[ 0 ][ 0 ] * m[ 1 ][ 1 ] - m[ 0 ][ 1 ] * m[ 1 ][ 0 ] ) < eps ) return;

		L[ 0 ] = ( sol[ 0 ] * m[ 1 ][ 1 ] - sol[ 1 ] * m[ 0 ][ 1 ] ) / det;
		L[ 1 ] = ( sol[ 1 ] * m[ 0 ][ 0 ] - sol[ 0 ] * m[ 1 ][ 0 ] ) / det;

		res.x = outer[ 0 ].x + q[ 0 ].x * L[ 0 ] + q[ 1 ].x * L[ 1 ];
		res.y = outer[ 0 ].y + q[ 0 ].y * L[ 0 ] + q[ 1 ].y * L[ 1 ];
		res.z = outer[ 0 ].z + q[ 0 ].z * L[ 0 ] + q[ 1 ].z * L[ 1 ];

		radius = dist( res, outer[ 0 ] );
		break;
	case 4:
		for( i = 0; i < 3; i++ )
		{
			q[ i ].x = outer[ i + 1 ].x - outer[ 0 ].x;
			q[ i ].y = outer[ i + 1 ].y - outer[ 0 ].y;
			q[ i ].z = outer[ i + 1 ].z - outer[ 0 ].z;
			sol[ i ] = dot( q[ i ], q[ i ] );
		}
		for( i = 0; i < 3; i++ )
			for( j = 0; j < 3; j++ )
				m[ i ][ j ] = dot( q[ i ], q[ j ] ) * 2;
		det = m[ 0 ][ 0 ] * m[ 1 ][ 1 ] * m[ 2 ][ 2 ] 
			+ m[ 0 ][ 1 ] * m[ 1 ][ 2 ] * m[ 2 ][ 0 ]
			+ m[ 0 ][ 2 ] * m[ 2 ][ 1 ] * m[ 1 ][ 0 ]
			- m[ 0 ][ 2 ] * m[ 1 ][ 1 ] * m[ 2 ][ 0 ]
			- m[ 0 ][ 1 ] * m[ 1 ][ 0 ] * m[ 2 ][ 2 ]
			- m[ 0 ][ 0 ] * m[ 1 ][ 2 ] * m[ 2 ][ 1 ];
		
		if( fabs( det ) < eps ) return;

		for( j = 0; j < 3; j++ )
		{
			for( i = 0; i < 3; i++ ) 
				m[ i ][ j ] = sol[ i ];
			L[ j ] = ( m[ 0 ][ 0 ] * m[ 1 ][ 1 ] * m[ 2 ][ 2 ] 
					+ m[ 0 ][ 1 ] * m[ 1 ][ 2 ] * m[ 2 ][ 0 ]
					+ m[ 0 ][ 2 ] * m[ 2 ][ 1 ] * m[ 1 ][ 0 ]
					- m[ 0 ][ 2 ] * m[ 1 ][ 1 ] * m[ 2 ][ 0 ]
					- m[ 0 ][ 1 ] * m[ 1 ][ 0 ] * m[ 2 ][ 2 ]
					- m[ 0 ][ 0 ] * m[ 1 ][ 2 ] * m[ 2 ][ 1 ] ) / det;
			for( i = 0; i < 3; i++ ) m[ i ][ j ] = dot( q[ i ], q[ j ] ) * 2;
		}
		res = outer[ 0 ];
		for( i = 0; i < 3; i++ )
		{
			res.x += q[ i ].x * L[ i ];
			res.y += q[ i ].y * L[ i ];
			res.z += q[ i ].z * L[ i ];
		}

		radius = dist( res, outer[ 0 ] );
		break;
	}
}

void minball( int n )
{
	ball( );
	if( nouter < 4 )
	{
		for( int i = 0; i < n; i++ )
		{
			if( dist( res, point[ i ] ) - radius > eps )
			{
				outer[ nouter ] = point[ i ];
				++nouter;
				minball( i );
				--nouter;
				if( i > 0 )
				{
					point_type Tt = point[ i ];
					memmove( &point[ 1 ], &point[ 0 ], sizeof( point_type ) * i );
					point[ 0 ] = Tt;
				}
			}
		}
	}
}

int main(int argc, char *argv[])
{
	while( scanf( "%d", &npoint ) && npoint )
	{
		for( int i = 0; i < npoint; i++ )
			scanf( "%lf%lf%lf", &point[ i ].x, &point[ i ].y, &point[ i ].z );
		for( int i = npoint; i < npoint * 2; i++ )
		{
			point[ i ].x = point[ i - npoint ].x;
			point[ i ].y = point[ i - npoint ].y;
			point[ i ].z = -point[ i - npoint ].z;
		}
		minball( npoint * 2 );
		if( fabs( res.x ) < eps ) res.x = 0;
		if( fabs( res.y ) < eps ) res.y = 0;
		printf( "%.3lf %.3lf\n", res.x, res.y );
	}
	return 0;
}
