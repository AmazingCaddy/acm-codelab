#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
const int maxn = 103;
const double eps = 1e-10;
int n;
double I[maxn][maxn], x[maxn][maxn], y[maxn][maxn], ans[maxn][maxn];

void init( )
{
	for( int i = 0; i < maxn; i++ )
	{
		I[i][i] = 1;
		for( int j = i + 1; j < maxn; j++ )
			I[i][j] = I[j][i] = 0;
	}
}

void matrix_jia( double a[][maxn], double b[][maxn] )
{
	for( int i = 0; i < n; i++ )
		for( int j = 0; j < n; j++ )
			a[i][j] = a[i][j] + b[i][j];
}

void matrix_chu( double a[][maxn], double b )
{
	for( int i = 0; i < n; i++ )
		for( int j = 0; j < n; j++ )
			a[i][j] /= b;
}

void matrix_mul( double a[][maxn], double b[][maxn] )
{
	double c[maxn][maxn];
	memset( c, 0, sizeof( c ) );
	for( int i = 0; i < n; i++ )
		for( int j = 0; j < n; j++ )
			for( int k = 0; k < n; k++ )
				c[i][j] = c[i][j] + a[i][k] * b[k][j];
	for( int i = 0; i < n; i++ )
		for( int j = 0; j < n; j++ )
			a[i][j] = c[i][j];
}

bool check( double a[][maxn] )
{
	for( int i = 0; i < n; i++ )
		for( int j = 0; j < n; j++ )
			if( fabs( a[i][j] ) > eps )
				return true;
	return false;
}

int main( )
{
	while( scanf("%d",&n) && n )
	{
		int cnt = 100;
		for( int i = 0; i < n; i++ )
			for( int j = 0; j < n; j++ )
				scanf("%lf",&x[i][j]);
		init( );
		memset( ans, 0, sizeof( ans ) );
		matrix_jia( ans, I );
		for( int i = 1; check( I ); i++ )
		{
			matrix_mul( I, x );
			matrix_chu( I, i * 1.0 );
			matrix_jia( ans, I );
		}
		for( int i = 0; i < n; i++ )
		{
			for( int j = 0; j < n; j++ )
				printf("%.2lf ", ans[i][j]);
			printf("\n");
		}
	}
	return 0;
}
