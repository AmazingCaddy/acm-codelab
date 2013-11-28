/*
    author: AmazingCaddy
    time: 18/05/2011 21:26:53 
*/
#include <iostream>
#include <complex>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int maxn = 104;

class HP
{
public:
	int len, s[ maxn ];
	HP( ) { ( *this ) = 0; }
	HP( int inte ) { ( *this ) = inte; }
	HP( const char *str ) { ( *this ) = str; }
	friend ostream & operator << ( ostream & cout, const HP & x );
	HP operator = ( int inte );
	HP operator = ( const char * str );
	HP operator + ( const HP & b );
};

ostream & operator << ( ostream & cout, const HP & x )
{
	for( int i = x.len; i >= 1; i-- ) cout << x.s[ i ];
	return cout;
}

HP HP::operator = ( const char *str )
{
	len = strlen( str );
	for( int i = 1; i <= len; i++ ) s[ i ] = str[ len - i ] - '0';
	return ( *this );
}

HP HP::operator = ( int inte )
{
	if( inte == 0 ) { len = 1; s[ 1 ] = 0; return ( *this ); }
	for( len = 0; inte > 0; ) { s[ ++len ] = inte % 10; inte /= 10; }
	return ( *this );
}

HP HP::operator + ( const HP & b )
{
	int i;
	HP c;
	c.s[ 1 ] = 0;
	for( i = 1; i <= len || i <= b.len || c.s[ i ]; i++ )
	{
		if( i <= len ) c.s[ i ] += s[ i ];
		if( i <= b.len ) c.s[ i ] += b.s[ i ];
		c.s[ i + 1 ] = c.s[ i ] / 10, c.s[ i ] %= 10;
	}
	c.len = i - 1;
	if( c.len == 0 ) c.len = 1;
	return c;
}
char buf[ maxn ];

int main( int ac, char * av[ ] )
{
	int cas;
	scanf( "%d", &cas );
	int k = 0;
	while( cas -- )
	{
		if( k ) printf( "\n" );
		else k = 1;
		HP sum( "0" );
		while( 1 )
		{
			scanf( "%s", buf );
			if( strcmp( buf, "0" ) == 0 ) break;
			sum = sum + HP( buf );
		}
		cout << sum << endl;
	}
	return 0;
}
