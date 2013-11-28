#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <complex>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

const int maxn = 1003;
map< string, int > m;
int p[maxn], Time[maxn], cnt[maxn];
char ch[maxn], ch1[maxn], ch2[maxn];
int N, M, K;

int team( int x ) { return ( x < N ? 1 : 2 ); }

int main(int argc, char *argv[])
{
	int T, q, r, t1, t2, last, e;
	while( scanf("%d%d%d",&N,&M,&K) != EOF )
	{
		m.clear( );
		//p2.clear( );
		for( int i = 0; i < N + M; i++ )
		{
			scanf("%s",ch);
			m[ch] = i;
			p[i] = 603;
		}
		memset( Time, 0, sizeof( Time ) );
		memset( cnt, 0, sizeof( cnt ) );
		last = -1;
		int i;
		for( i = 0; i < K; i++ )
		{
			scanf("%s",ch);
			if( ch[0] == 'Q' )
			{
				scanf("%s%d",ch,&T);
				q = m[ch];
				p[q] += ( T - Time[q] );
				printf("%d\n",p[q]);
				Time[q] = T;
			}
			else
			{
				scanf("%s%s%d",ch1,ch2,&T);
				q = m[ch1], r = m[ch2];
				p[q] += ( T - Time[q] );
				p[r] += ( T - Time[r] );
				Time[q] = T, Time[r] = T;

				t1 = team( q );
				t2 = team( r );
				
				if( t1 != t2 )
				{
					//last = t1;
					p[q] += 400;
					p[r] -= 300;
					if( p[r] < 0 ) p[r] = 0;
					cnt[q] = 1;
					break;
				}
				else
				{
					p[r] -= 300; 
					if( p[r] < 0 ) p[r] = 0;
				}
			}
		}
		for( int j = i + 1; j < K; j++ )
		{
			scanf("%s",ch);
			if( ch[0] == 'Q' )
			{
				scanf("%s%d",ch,&T);
				q = m[ch];
				p[q] += ( T - Time[q] );
				printf("%d\n",p[q]);
			}
			else
			{
				scanf("%s%s%d",ch1,ch2,&T);
				q = m[ch1], r = m[ch2];

				p[q] += ( T - Time[q] );
				p[r] += ( T - Time[r] );

				Time[q] = T, Time[r] = T;

				t1 = team( q );
				t2 = team( r );
				
				if( t1 != t2 )
				{

					p[q] += 200;
					e = 0;
					if( cnt[q] >= 3 )
					{
						e = 50 * ( cnt[q] - 2 );
						if( e > 200 ) e = 200;
					}

					p[q] += e;
					p[r] -= 300;
					if( p[r] < 0 ) p[r] = 0;
					cnt[r] = 0;

				}
				else 
				{
					p[r] -= 300;
					if( p[r] < 0 ) p[r] = 0;
					cnt[r] = 0;
				}
			}
		}
	}
	return 0;
}
