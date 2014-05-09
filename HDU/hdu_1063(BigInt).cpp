/*
    author: AmazingCaddy
    time: 27/05/2011 18:53:40 
    大正数 && 高精度浮点数
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

const int maxlen = 300;
class HP { 
public :
	int len, s[ maxlen ];
	HP( ) { ( *this ) = 0; }
	HP( int inte ) { ( *this ) = inte; }
	HP( const char *str ) { ( *this ) = str; }
	friend ostream & operator << ( ostream & cout , const HP &x );
	HP operator = ( int inte );
	HP operator = ( const char * str );
	HP operator * ( const HP &b ); HP operator + ( const HP &b );
	HP operator - ( const HP &b ); HP operator / ( const HP &b );
	HP operator % ( const HP &b ); int Compare ( const HP &b );
};

ostream & operator<<(ostream & cout , const HP &x )
{
 	for( int i = x.len; i >= 1; i-- )
 		cout << x.s[ i ];
 	return cout;
}

HP HP::operator = ( const char * str )
{
	len = strlen( str );
	for( int i = 1; i <= len; i++ )
	 	s [ i ] = str[ len - i ] - '0';
	return *this;
}

HP HP::operator = ( int inte )
{
	if( inte == 0 ) {  len = 1; s[ 1 ] = 0; return ( *this ); }
	for( len = 0; inte > 0; )
	{ 
		s[ ++len ] = inte % 10;
		inte /= 10;
	}
	return ( *this );
}

HP HP::operator * ( const HP &b )
{
	int i ,j;
	HP c; 
	c.len = len + b.len;
	for( i = 1; i <= c.len; i++ ) c.s[ i ] = 0;
	for( i = 1; i <= len; i++ )
	 	for( j = 1; j <= b.len; j++ )
	 		c.s[ i + j - 1 ] += s[ i ] * b.s[ j ];
	for( i = 1; i < c.len; i++ )
	{
		c.s[ i + 1 ] += c.s[ i ] / 10;
	 	c.s[ i ] %= 10;
 	}
	while( c.s[ i ] ) { c.s [ i + 1 ] = c.s[ i ] / 10; c.s[ i ] %= 10; i++; }
	while( i > 1 && ! c.s[ i ] ) i--;
 	c.len = i;
	return c;
}

HP HP::operator + ( const HP &b )
{
	int i; HP c; c.s[ 1 ] = 0;
	for( i = 1; i <= len || i <= b.len || c.s[ i ]; i ++ )
	{
		if( i <= len ) c.s[ i ] += s[ i ];
		if( i <= b.len ) c.s[ i ] += b.s[ i ];
		c.s[ i + 1 ] = c.s[ i ] / 10 ;
		c.s[ i ] %= 10;
	}
	c.len = i - 1;
	if( c.len == 0 ) c.len = 1;
	return c ;
}

HP HP::operator - ( const HP &b )
{
	int i, j; HP c;
	for( i = 1, j = 0; i <= len; i++ ) 
	{
		c.s[ i ] = s[ i ] - j; 
		if( i <= b.len ) c.s[ i ] -= b.s[ i ] ;
		if( c.s[ i ] < 0 )
		{
			j = 1; c.s[ i ] += 10; 
		} 
		else j = 0;
	}
	c.len = len; 
	while( c.len > 1 && !c.s[ c.len ] ) c.len--;
	return c;
}

int HP::Compare ( const HP &y )
{
	if( len > y.len ) return 1 ;
	if( len < y.len ) return -1;
	int i = len;
	while( ( i > 1 ) && ( s[ i ] == y.s[ i ] ) ) i--;
	return s[ i ] - y.s[ i ];
}

HP HP::operator / ( const HP &b )
{
	int i, j; HP d( 0 ) , c ;
	for( i = len; i > 0; i-- )
	{
		if( !( d.len == 1 && d.s[ 1 ] == 0 ) )
		{
	 		for( j = d.len; j > 0; j-- ) 
	 			d.s[ j + 1 ] = d.s[ j ];
 			 ++d.len;
		}
		d.s[ 1 ] = s[ i ]; 
		c.s[ i ] = 0;
		while( ( j = d.Compare( b ) ) >= 0 )
		{ 
			d = d - b; 
			c.s[ i ]++;
			if ( j == 0 ) 
			break; 
		}
	}
	c.len = len; 
	while( ( c.len > 1 ) && ( c.s[ c.len ] == 0 ) ) c.len--;
	return c;
}

HP HP::operator % ( const HP &b )
{
	int i, j; HP d( 0 );
	for( i = len; i > 0; i-- ) 
	{
		if( !( d.len == 1 && d.s[ 1 ] == 0 ) )
		{ 
			for( j = d.len; j > 0; j-- ) d.s [ j + 1 ] = d.s[ j ]; 
			++d.len; 
		}
		d.s[ 1 ] = s[ i ];
		while( ( j = d.Compare ( b ) ) >= 0 )
		{ 
			d = d - b; 
			if ( j == 0 )
		 	break; 
	 	}
	}
	return d;
}

const int fprec = 150; // floating-point precision
HP zero = 0;
class FS
{ 
public :
	FS( ); void SetZero( );
	FS( int inte ) { ( *this ) = inte; }
	FS( char *s ) { ( *this ) = s; }
	FS operator = ( char *s ); FS operator = ( int inte );
	FS operator + ( FS b ); FS operator - ( FS b );
	FS operator * ( FS b ); FS operator / ( FS b );
	friend ostream & operator << ( ostream & cout, FS x );
	int sign, prec;
	HP num ;
};

void FS::SetZero( ) { sign = 1; num = 0; prec = 0; }

FS::FS( ) { SetZero( ); }

ostream & operator << ( ostream & cout , FS x )
{
	if( x.sign < 0)  cout << "-";
	int i, k, low = 1;
	for( i = x.num.len; i > x.prec; i-- ) cout << x.num.s[ i ];
	//if( x.num.len <= x.prec ) cout << "0";
	if( x.num.Compare( zero ) == 0 ) { cout <<".0"; return cout; }
	k = i;
	while( k > 0 && x.num.s[ k ] == 0 ) k--;
	if( k == 0 ) { /*cout << ".0";*/ return cout; }
	cout << ".";
	if( x.num.len < x.prec ) 
	for( int j = 0; j < x.prec - x.num.len; j++ ) cout << "0";
	while( x.num.s[ low ] == 0 ) low++;
	while( i >= low ) cout << x.num.s[ i-- ];
	return cout;
}

FS FS::operator = ( int inte )
{
	prec = 0;
	if( inte >= 0 ) { sign = 1; num = inte; }
	else
	{ 
		sign = -1;
		num = -inte;
	}
	return ( *this );
}

FS FS::operator = ( char *s )
{
	int p, i, j, l;
	SetZero( );
	if( s [ 0 ] == '-' ) { sign = -1; s++; }
	if( s [ 0 ] == '+' ) { sign = 1; s++; }
	l = strlen( s );
	for( p = 0; p < l; p++ ) if ( s[ p ] == '.' ) break;
	if( p == l ) prec = 0; else prec = l - 1 - p;
	for( i = l - 1, j = 0 ; i >= 0; i-- ) 
		if( s[ i ] != '.' ) num.s[ ++j ] = s[ i ] - '0';
	while( j > 1 && num.s[ j ] == 0 ) --j; 
	num.len = j;
	return ( *this );
}

void LShift ( FS &a, int sl )
{
	a.prec += sl; a.num.len += sl; int i;
	for( i = a.num.len; i > sl; i-- ) a.num.s[ i ] = a.num.s[ i - sl ];
	while( i > 0 ) a.num.s[ i-- ] = 0;
}

void RShift ( FS &a, int sl )
{
	a.prec -= sl; a.num.len -= sl; int i;
	for( i = 1; i <= a.num.len; i++ ) a.num.s[ i ] = a.num.s[ i + sl ];
}

FS FS::operator + ( FS b )
{
	FS c;
	if( prec > b.prec ) LShift ( b, prec - b.prec ); 
	else if( prec < b.prec ) LShift ( ( *this ), b.prec - prec );
	if( sign == b.sign ) 
	{
		c.sign = sign; 
		c.prec = prec; 
		c.num = num + b.num;
		if( c.num.Compare ( zero ) == 0 ) c.SetZero( );
	}
	else 
	{
		c.prec = prec;
		if( num.Compare( b.num ) == 0 ) c.SetZero( ); 
		else if( num.Compare( b.num ) > 0 ) { c.sign = sign; c.num = num - b.num; } 
		else if( num.Compare( b.num ) < 0 ) { c.sign = b.sign; c.num = b.num - num; }
		if( c.num.Compare( zero ) == 0 ) c.SetZero( );
	}
	if( c.prec > fprec ) RShift( c, c.prec - fprec );
	return c;
}

FS FS::operator - ( FS b )
{
	b.sign = -b.sign;
	FS c = ( *this ) + b;
	b.sign = -b.sign;
	return c;
}

FS FS::operator * ( FS b )
{
	FS c ;
	c.sign = sign * b.sign;
	c.prec = prec + b.prec;
	c.num = num * b.num;
	if ( c.num.Compare ( zero ) == 0 ) c.SetZero( );
	if ( c.prec > fprec ) RShift ( c, c.prec - fprec );
	return c ;
}

FS FS::operator / ( FS b ) // 355/133 = 3.1415929203539823008849557522124
{
	FS c, d ; // c = d / b
	d = ( *this ); LShift( d, fprec );
	c.sign = d.sign * b.sign;
	c.prec = d.prec;
	LShift( d, b.prec );
	c.num = d.num / b.num;
	if( c.prec > fprec ) RShift( c, c.prec - fprec );
	return c ;
}

char buf[ 50 ];

int main( int ac, char * av[ ] )
{
	int n;
	while( scanf( "%s%d", buf, &n ) != EOF )
	{
		FS ans( 1 );
		FS a( buf );
		for( int i = 0; i < n; i++ )
			ans = ans * a;
		cout << ans << endl;
	}
	return 0;
}
