#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <complex>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

const int maxn = 6402;

bool vis[maxn];
int p[maxn];
int plen,cnt;

bool v[10000005];

void prime( )
{
	int i, j, k;
	plen = 0;
	memset( vis, false, sizeof( vis ) );
	for( i = 2, k = 4; i < maxn; ++i, k += i + i - 1 )
	{
		if( !vis[i] )
		{
			p[plen++] = i;
			if( k < maxn )
			{
				for( j = k; j < maxn; j += i )
					vis[j] = true;
			}
		}
	}
}

int main(int argc, char *argv[])
{
	//freopen("out1.txt","w",stdout);
	int i, j, t;
	prime( );
	cnt = 0;
	memset( v, true, sizeof( v ) );
	for( j = 0; j < plen; j++ )
	{
		t = p[j];
		for( i = 30000000/t*t; i < 30000000; i += t );
		for( ; i < 40000000; i += t )
			v[i-30000000] = false;
	}
	for( i = 0; i < 10000000; i++ )
		if( v[i] )
		printf("%d\n",i+30000000);
	return 0;
}
