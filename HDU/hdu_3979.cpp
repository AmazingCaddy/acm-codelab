/*
	author: AmazingCaddy
	time:	
*/
#include <cstdio>
#include <complex>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <vector>
#include <map>
#include <queue>
using namespace std;

typedef long long ll;

const int maxn = 10004;
const double pi = acos( -1.0 );
const double inf = 1e20;
const double eps = 1e-8;

struct node {
	int atknum;
	int atk;
	int hp;
	bool operator < ( const node & b ) const {
		return atknum * b.atk < atk * b.atknum;
	}
};
node monster[ maxn ];

int main(int argc, char *argv[]) {
	int cas, n, m;
	scanf( "%d", &cas );
	for( int t = 1; t <= cas; t++ ) {
		scanf( "%d%d", &n, &m );
		int sum = 0;
		for( int i = 0; i < n; i++ ) {
			scanf( "%d%d", &monster[ i ].hp, &monster[ i ].atk );
			monster[ i ].atknum = ( monster[ i ].hp + m - 1 ) / m;
			sum += monster[ i ].atk;
		}
		sort( monster, monster + n );
		ll ans = 0;
		for( int i = 0; i < n; i++ ) {
			ans = ans + (ll)monster[ i ].atknum * sum;
			sum -= monster[ i ].atk;
		}
		printf( "Case #%d: ", t );
		cout << ans << endl;
	}
	return 0;
}
