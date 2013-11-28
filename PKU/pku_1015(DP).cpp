#include <cstdio>
#include <iostream>
#include <cstring>
#include <complex>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

const int maxn = 900;
int dp[ 2 ][ 22 ][ maxn ];
int path[ 203 ][ 22 ][ maxn ];
int sub[ 203 ], plu[ 203 ];

void update( int now, int k, int a, int b, int c, int d ){
	if( dp[ now ][ k ][ a ] == -1 || dp[ now ][ k ][ a ] < b ){
		dp[ now ][ k ][ a ] = b;
		path[ d ][ k ][ a ] = c;
	}
}

int main(int argc, char *argv[]){
	int n, m, a, b, tc = 1;
	while( 1 ){
		scanf("%d%d",&n,&m);
		if( n == 0 && m == 0 ) break;
		for( int i = 0; i < n; i++ ){
			scanf("%d%d",&a, &b);
			sub[ i ] = a - b;
			plu[ i ] = a + b;
		}

		int pre = 0, now = 1, mid = 450;
		memset( dp[ pre ], -1, sizeof( dp[ pre ] ) );
		dp[ pre ][ 0 ][ mid ] = 0;

		for( int i = 0; i < n; i++ ){
			memset( dp[ now ], -1, sizeof( dp[ now ] ) );
			for( int j = 0; j <= m; j++ ){
				for( int k = 0; k < maxn; k++ ){
					if( dp[ pre ][ j ][ k ] != -1 ){
						if( j < m && k + sub[ i ] >= 0 ){	
							update( now, j+1, k+sub[i], dp[pre][j][k]+plu[i], i, i+1 );
						}
						update( now, j, k, dp[pre][j][k], path[i][j][k], i+1 );
					}
				}
			}
			swap( now, pre );
		}

		int j;
		for( j = 0; dp[pre][m][mid+j] < 0 && dp[pre][m][mid-j] < 0; j++ );
		int k = dp[pre][m][mid+j] > dp[pre][m][mid-j] ? mid + j : mid - j;

		vector<int> ret;
		int kk = k, mm = m;
		while( m ){
			int id = path[ n ][ m ][ k ];
			ret.push_back( id );
			--m;
			k -= sub[ id ];
			n = id;
		}
		sort( ret.begin( ), ret.end( ) );
		printf("Jury #%d\nBest jury has value ",tc++);
		int p = ( dp[ pre ][ mm ][ kk ] + kk - mid ) / 2;
		int q = ( dp[ pre ][ mm ][ kk ] - kk + mid ) / 2;
		printf("%d for prosecution and value %d for defence:\n",p,q );
		for( int i = 0; i < ret.size(); i++ )
			printf(" %d",ret[i]+1);
		printf("\n");
	}
	return 0;
}
