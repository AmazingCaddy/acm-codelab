/*
	author: AmazingCaddy
	time:	2011/11/2	21:42
	solve:	sigma{ i = 1,...,(n-1); j = 1,...,floor((n-1)/i) } ( n - i * j )
*/
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <complex>
#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;
const ll mod = 100000007;

ll solve( ll n ) {
	ll m = n - 1;
	ll tmp = (int)sqrt( 1.0 * m );
	// 枚举商
	ll sum = 0;
	for( ll i = 1; i <= tmp; i++ ) {
		ll l = m / ( i + 1 ) + 1;
		ll r = m / i;
		ll len = r - l + 1;
		sum = sum + ( len * i % mod * n % mod );
		sum = sum - ( ( l + r ) * len / 2 ) % mod * ( ( 1 + i ) * i / 2 ) % mod;
		sum %= mod;
	}
	for( ll i = 1; m / i > tmp; i++ ) {
		sum = sum + m / i * n;
		sum %= mod;
		sum = sum - i * ( ( 1 + m / i ) * ( m / i ) / 2 % mod );
		sum %= mod;
	}
	return sum < 0 ? sum + mod : sum;
}

int main(int argc, char *argv[]){
	ll n;
//	freopen( "out", "w", stdout );
//	for( int i = 1; i <= 1000; i++ ) {
//		printf( "%d %lld\n", i, solve( i ) );
//	}
	while( scanf( "%lld", &n ) != EOF ) {
		printf( "%lld\n", solve( n ) );
	}
	return 0;
}
