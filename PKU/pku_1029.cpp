#include <cstdio>
#include <iostream>
#include <cstring>
#include <complex>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

const int maxn = 1005;
int vis[ maxn ], w[ maxn ], t[ maxn ];

int main(int argc, char *argv[])
{
	int a, b, n, m, tot, p;
	char ch[ 10 ];
	while( scanf("%d%d",&n,&m) != EOF )
	{
		memset( vis, 0, sizeof( vis ) );
		memset( w, 0, sizeof( w ) );
		tot = 0;
		for( int i = 0; i < m; i++ )
		{
			scanf("%d",&p);
			for( int j = 0; j < p * 2; j++ )
				scanf("%d",&t[j]);
			scanf("%s",ch);
			if( ch[0] == '=' )
			{
				for( int j = 0; j < p * 2; j++ )
					vis[ t[ j ] ] = 1;
			}
			else
			{
				tot++;
				if( ch[0] == '<' )
				{
					for( int j = 0; j < p; j++ )
						w[ t[ j ] ]--;
					for( int j = p; j < p * 2; j++ )
						w[ t[ j ] ]++;
				}
				else
				{
					for( int j = 0; j < p; j++ )
						w[ t[ j ] ]++;
					for( int j = p; j < p * 2; j++ )
						w[ t[ j ] ]--;
				}
			}
		}
		int pos = -1, cnt = 0;
		for( int i = 1; i <= n; i++ )
		{
			if( vis[i] )continue;
			if( abs( w[ i ] ) == tot )
				cnt++, pos = i;
		}
		if( cnt == 1 )printf("%d\n",pos);
		else printf("0\n");
	}
	return 0;
}
