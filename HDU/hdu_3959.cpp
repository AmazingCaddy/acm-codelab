/*
	author: AmazingCaddy
	time:	2011/9/5	16:45
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

ll gcd( ll a, ll b ) {
	return ( b ? gcd( b, a % b ) : a );
}

int main(int argc, char *argv[]) {
	int M, N;
	int cas;
	scanf( "%d", &cas );
	for( int t = 1; t <= cas; t++ ) {
		scanf( "%d%d", &N, &M );
		int cnt = 0;
		ll pow_m = 1;
		while( pow_m < N ) {
			pow_m *= M;
			cnt++;
		}
		ll ans1 = N, ans2 = pow_m * cnt;
		ll d = gcd( ans1, ans2 );
		printf( "Case %d: ", t );
		cout << ( ans2 / d ) << "/" << ( ans1 / d ) << endl;
	}
	return 0;
}
