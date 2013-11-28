#include <cstdio>
#include <iostream>
#include <cmath>
#include <complex>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
const int maxn = 10;

double a[maxn][maxn];
double s[maxn][maxn];
double dp[16][maxn][maxn][maxn][maxn];
bool vis[16][maxn][maxn][maxn][maxn];

double minn( double x, double y ) { return ( x < y ? x : y ); }

void init( )
{
	memset( vis, false, sizeof( vis ) );
	for( int i = 0; i <= 8; i++ )
		s[i][0] = s[0][i] = 0;
	for( int i = 1; i <= 8; i++ )
	{
		double sum = 0;
		for( int j = 1; j <= 8; j++ )
		{
			sum += a[i][j];
			s[i][j] = s[i-1][j] + sum;
		}
	}
}

double getS( int x1, int y1, int x2, int y2 )
{
	double t = s[x2][y2] - s[x2][y1-1] - s[x1-1][y2] + s[x1-1][y1-1];
	return t * t;
}

double Dynamic( int k, int x1, int y1, int x2, int y2 )
{
	if( k == 1 ) return getS( x1, y1, x2, y2 );
	if( vis[k][x1][y1][x2][y2] ) return dp[k][x1][y1][x2][y2];
	double min = 1e20;
	for( int i = x1; i < x2; i++ )
	{
		double p = Dynamic( k - 1, i + 1, y1, x2, y2 ) + getS( x1, y1, i, y2 );
		min = minn( min, p );
		p = Dynamic( k - 1, x1, y1, i, y2 ) + getS( i + 1, y1, x2, y2 );
		min = minn( min, p );
	}
	for( int i = y1; i < y2; i++ )
	{
		double q = Dynamic( k - 1, x1, y1, x2, i ) + getS( x1, i + 1, x2, y2 );
		min = minn( min, q );
		q = Dynamic( k - 1, x1, i + 1, x2, y2 ) + getS( x1, y1, x2, i );
		min = minn( min, q );
	}
	vis[k][x1][y1][x2][y2] = true;
	dp[k][x1][y1][x2][y2] = min;
	return min;
}

int main(int argc, char *argv[])
{
	int n;
	while( scanf("%d",&n) != EOF )
	{
		for( int i = 1; i <= 8; i++ )
			for( int j = 1; j <= 8; j++ )
				scanf("%lf",&a[i][j]);
		init( );
		double ans = sqrt( Dynamic( n, 1, 1, 8, 8 ) / n - s[8][8] * s[8][8] / ( n * n ) );
		printf("%.3lf\n",ans);
	}
	return 0;
}
