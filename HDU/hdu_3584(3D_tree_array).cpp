#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <complex>
#include <algorithm>
#include <cmath>
#include <cstring>
#define lowbit( x ) ((x)&(-(x)))
using namespace std;
typedef __int64 ll;

const int maxn = 103;

int tree[maxn][maxn][maxn];
int n, m;

void update( int x, int y, int z )
{
	while( x <= n )
	{
		int yy = y;
		while( yy <= n )
		{
			int zz = z;
			while( zz <= n )
			{
				tree[x][yy][zz] ^= 1;
				zz += lowbit( zz );
			}
			yy += lowbit( yy );
		}
		x += lowbit( x );
	}
}

int query( int x, int y, int z )
{
	int sum = 0;
	while( x > 0 )
	{
		int yy = y;
		while( yy > 0 )
		{
			int zz = z;
			while( zz > 0 )
			{
				sum ^= tree[x][yy][zz];
				zz -= lowbit( zz );
			}
			yy -= lowbit( yy );
		}
		x -= lowbit( x );
	}
	return sum;
}

void update( int x1, int y1, int z1, int x2, int y2, int z2 )
{
	update( x1, y1, z1 );

	update( x2 + 1, y1, z1 );
	update( x1, y2 + 1, z1 );
	update( x1, y1, z2 + 1 );

	update( x1, y2 + 1, z2 + 1 );
	update( x2 + 1, y1, z2 + 1 );
	update( x2 + 1, y2 + 1, z1 );

	update( x2 + 1, y2 + 1, z2 + 1 );
}

int main(int argc, char *argv[])
{
	
	int op, x1, y1, z1, x2, y2, z2;
	while( scanf("%d%d",&n,&m) != EOF )
	{
		memset( tree, 0, sizeof( tree ) );
		for( int i = 0; i < m; i++ )
		{
			scanf("%d",&op);
			if( op == 0 )
			{
				scanf("%d%d%d",&x1,&y1,&z1);
				printf("%d\n",query( x1, y1, z1 ));
			}
			else
			{
				scanf("%d%d%d%d%d%d",&x1,&y1,&z1,&x2,&y2,&z2);
				update( x1, y1, z1, x2, y2, z2 );
			}
		}
	}
	return 0;
}
