/*
	author: AmazingCaddy
	time:	2011/7/29  12:47
	f(n+1) = PI (-1)^i*C(n,i+1)*f(n-i) { 0 <= i < n }
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

const int mod = 112233;
int Inverse[ 5 ][ 200 ];
int A[ 1000010 ];

int pow_mod( int a, int b, int p ) {
	int ans = 1, d = a % p;
	while( b ) {
		if( b & 1 ) ans = ans * d % p;
		d = d * d % p;
		b >>= 1;
	}
	return ans;
}
void ex_gcd( int a, int b, int &d, int &x, int &y ) {
	if( !b ) { d = a; x = 1; y = 0; }
	else {
		ex_gcd( b, a % b, d, y, x );
		y -= x * ( a / b );
	}
}
int Inv( int a, int p ) {
	return pow_mod( a, p - 2, p );
}
int CRT( int a1, int m1, int a2, int m2 ) {
	int d, x, y;
	// let a == a1 * k1 + a2 * k2 mod m1*m2
	// k1 == 1 mod m1, k1 == 0 mod m2
	// k2 == 0 mod m1, k2 == 1 mod m2
	ex_gcd( m1, m2, d, x, y );
	ll k1 = y * m2, k2 = x * m1;
	int t = ( a1 * k1 + a2 * k2 ) % ( m1 * m2 );
	return t < 0 ? t + m1 * m2 : t;
}
int fac[ ] = { 3, 11, 19, 179 };
void getInv( ) {
	for( int i = 0; i < 4; i++ )
		for( int j = 1; j < fac[ i ]; j++ )
			Inverse[ i ][ j ] = Inv( j, fac[ i ] );
}
int main(int argc, char *argv[]) {
	int n;
	getInv( );
	while( scanf( "%d", &n ) != EOF ) {
		for( int i = 0; i < n; i++ ) {
			scanf( "%d", &A[ i ] );
			A[ i ] %= mod;
		}
		int a = 0, b = 1;
		for( int i = 0; i < 4; i++ ) {
			int p = fac[ i ], cntp = 0, sum = 0, flag = -1, C = 1;
			// C(n,j+1) = C(n,j)/(j+1)*(n-j)
			for( int j = 0; j < n; j++ ) {
				flag *= ( -1 );
				int x = n - j, y = j + 1;
				while( x % p == 0 ) {
					cntp++;
					x /= p;
				}
				while( y % p == 0 ) {
					cntp--;
					y /= p;
				}
				C = C * (ll)x * Inverse[ i ][ y % p ] % p;
				if( cntp == 0 ) {
					sum = ( sum + (ll)flag * C * A[ n - j - 1 ] ) % p;
				}
			}
			if( sum < 0 ) sum += p;
			a = CRT( a, b, sum, p );
			b *= p;
		}
		printf( "%d\n", a );
	}
	return 0;
}
