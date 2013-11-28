#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <complex>
#include <queue>
using namespace std;

struct point
{
	int x, y;
}p[ 256 ];//pp[ 203 ];

int gcd( int a, int b ) { return ( b ? gcd( b, a % b ) : a ); }
//bool samepoint( point a, point b ) { return a.x == b.x && a.y == b.y; }
//bool cmp( const point & a, const point & b )
//{
//	return a.x < b.x || a.x == b.x && a.y < b.y;
//}
const int maxn = 65536;
const int P = 65521;

struct Hash
{
	int a, b;
	int nt;
}h[ maxn << 1 ];

int flg[ maxn ], top, idx;
int vert, hori, sum;
int f( int a, int b ) { return ( a * a + b * b ) % P; }
void inithash( ) { top = maxn; ++idx; }

void ins( int a, int b )
{
	int id = f( a, b );
	int buf = id;
	if( flg[ id ] != idx )
	{
		flg[ id ] = idx;
		h[ id ].a = a;
		h[ id ].b = b;
		h[ id ].nt = -1;
		sum++;
		return ;
	}
	while( id != -1 )
	{
		if( h[ id ].a * b == a * h[ id ].b )
		{
			return ;
		}
		id = h[ id ].nt;
	}
	id = buf;
	h[ top ].nt = h[ id ].nt;
	h[ top ].a = a;
	h[ top ].b = b;
	h[ id ].nt = top++;
	sum++;
	return ;
}

int main(int argc, char *argv[])
{
	int n;
	while( scanf("%d",&n) != EOF )
	{
		for( int i = 0; i < n; i++ )
			scanf("%d%d",&p[i].x,&p[i].y);
		inithash( );
		sum = vert = hori = 0;
		for( int i = 0; i < n; i++ )
		{
			for( int j = i + 1; j < n; j++ )
			{
				int a = p[ i ].x - p[ j ].x;
				int b = p[ i ].y - p[ j ].y;
				//if( a == 0 && b == 0 ) { continue; }
				//printf("a == %d,  b == %d\n",a,b);
				if( a == 0 )
				{
					if( !vert ) { sum++; vert = 1; }
					continue; 
				}
				if( b == 0 )
				{
					if( !hori ) { sum++; hori = 1; }
					continue;
				}
 				//if( a == 0 || b == 0 ) { sum -= ins( a, b ); continue; }
				int d = gcd( abs( a ), abs( b ) );
				ins( a / d, b / d );
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}
