#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <complex>
#include <queue>
using namespace std;

const int maxn = 10003;
int vis[ maxn ];

int main(int argc, char *argv[])
{
	int Z, I, M, L, t = 1;
	while( 1 )
	{
		scanf("%d%d%d%d",&Z,&I,&M,&L);
		if( Z == 0 && I == 0 && M == 0 && L == 0 ) break;
		memset( vis, 0, sizeof( vis ) );
		int i = 0;
		while( !vis[ L ] )
		{
			vis[ L ] = ++i;
			L = ( Z * L + I ) % M;
		}
		printf("Case %d: %d\n",t++, i - vis[ L ] + 1);
	}
	return 0;
}
