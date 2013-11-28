#include <map>
#include <set>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define oo 0x3f3f3f3f

int max( int a, int b ) { return ( a > b ? a : b ); }

char name[15];
map<string,int> id;
map<int,int> l[2];
int num,ans;
int cnt[2][200000];

int main()
{
    int cas;
	//freopen("1003.in","r",stdin);
	//freopen("out.txt","w",stdout);
    scanf("%d",&cas);
    while( cas-- )
    {
        int m;
        scanf("%d",&m);
        num = 0;
        id.clear( );
        for( int i = 0; i < 2; i++ )l[i].clear( );
        while( m-- )
        {
            int op;
            scanf("%d %s",&op,name);
            if( op==1 )
            {
                int x,y;
                scanf("%d %d",&x,&y);
                id[name] = ++num;
                for( int i = 0, tt; i < 2; i++ )
                {
                    tt=0;
                    if( i & 1 ) tt = x + y;
                    else tt = x - y;
                    l[i][tt]++;
                    cnt[i][num] = tt;
                }
            }
            else
            {
                int tid = id[name];
                for( int i = 0, tt; i < 2; i++ )
                {
                    tt = cnt[i][tid];
                    l[i][tt]--;
                    if( l[i][tt] == 0 )
                    {
                        l[i].erase( tt );
                    }
                }
                id.erase( name );
			}
			int MAX;
			ans = -oo;
			for( int i = 0; i < 2; i++ )
			{
				if( l[0].empty( ) ) ans = max( ans, -1 );
				else
				{
					MAX = l[i].rbegin()->first - l[i].begin()->first;
					ans = max( ans, MAX );
				}
			}
            printf("%d\n",ans);
        }
        puts("");
    }    
}
