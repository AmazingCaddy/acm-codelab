/*
	author: AmazingCaddy
	time: 2011/4/3  14:54
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
using namespace std;

const int maxn = 10004;
char ans[ 20 ];
char buf[ 20 ];
const int m[ ] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int mon[ 13 ];
int data[ 20 ];
int d[ 20 ];
int num[ 20 ];

bool leapyear( int n )
{
	if( n % 4 == 0 )
	{
		if( n % 100 == 0 ) return n % 400 == 0;
		return n % 4 == 0;
	}
	return 0;
}

void compute( int i, int j, int k )
{
	d[ 6 ] = i / 10, d[ 7 ] = i % 10;
	d[ 8 ] = j / 10, d[ 9 ] = j % 10;
	d[ 10 ] = k / 10, d[ 11 ] = k % 10;
}

int compute1( int i, int j, int k )
{
	for( int p = 9; p >= 6; p-- )
		d[ p ] = i % 10, i /= 10;
	d[ 10 ] = j / 10, d[ 11 ] = j % 10;
	d[ 12 ] = k / 10, d[ 13 ] = k % 10;
	int tmp = 0;
	for( int i = 0; i < 17; i++ )
		tmp = ( tmp * 2 + d[ i ] ) % 11;
	tmp = tmp * 2 % 11;
	return tmp;
}

void solve( )
{
	int len = strlen( buf );
	if( len == 15 )
	{
		for( int i = 0; i < 17; i++ )
			data[ i ] = buf[ i ] - '0';
		int Min = 100;
		memcpy( ans, buf, sizeof( buf ) );
		for( int i = 0; i < 100; i++ )
		{
			memcpy( mon, m, sizeof( m ) );
			if( leapyear( i + 1900 ) ) mon[ 2 ]++;
			for( int j = 1; j <= 12; j++ )
			{
				for( int k = 1; k <= mon[ j ]; k++ )
				{
					compute( i, j, k );
					int sum = 0;
					for( int p = 6; p < 12; p++ )
						sum += ( data[ p ] != d[ p ] );
					if( sum < Min )
					{
						Min = sum;
						for( int p = 6; p < 12; p++ )
							ans[ p ] = d[ p ] + '0';
					}
				}
			}
		}
		for( int i = 0; i < 11; i++ )
		{
			memcpy( mon, m, sizeof( m ) );
			if( leapyear( i + 2000 ) ) mon[ 2 ]++;
			for( int j = 1; j <= 12; j++ )
			{
				for( int k = 1; k <= mon[ j ]; k++ )
				{
					compute( i, j, k );
					int sum = 0;
					for( int p = 6; p < 12; p++ )
						sum += ( data[ p ] != d[ p ] );
					if( sum < Min )
					{
						Min = sum;
						for( int p = 6; p < 12; p++ )
							ans[ p ] = d[ p ] + '0';
					}
				}
			}
		}
		memcpy( mon, m, sizeof( m ) );
		for( int j = 1; j <= 3; j++ )
		{
			for( int k = 1; k <= mon[ j ]; k++ )
			{
				compute( 11, j, k );
				int sum = 0;
				for( int p = 6; p < 12; p++ )
					sum += ( data[ p ] != d[ p ] );
				if( sum < Min )
				{
					Min = sum;
					for( int p = 6; p < 12; p++ )
						ans[ p ] = d[ p ] + '0';
				}
			}
		}
		for( int k = 1; k <= 2; k++ )
		{
			compute( 11, 4, k );
			int sum = 0;
			for( int p = 6; p < 12; p++ )
				sum += ( data[ p ] != d[ p ] );
			if( sum < Min )
			{
				Min = sum;
				for( int p = 6; p < 12; p++ )
					ans[ p ] = d[ p ] + '0';
			}
		}
	}
	else
	{
		for( int i = 6; i < 14; i++ )
			data[ i ] = buf[ i ] - '0';
		int checksum = ( buf[ 17 ] == 'X' ? 10 : buf[ 17 ] - '0' );
		int Min = 100;
		memcpy( ans, buf, sizeof( buf ) );
		for( int i = 1900; i < 2011; i++ )
		{
			memcpy( mon, m, sizeof( m ) );
			if( leapyear( i ) ) mon[ 2 ]++;
			for( int j = 1; j <= 12; j++ )
			{
				for( int k = 1; k <= mon[ j ]; k++ )
				{
					int tmp = compute1( i, j, k );
					int sum = 0;
					for( int p = 6; p < 14; i++ )
						sum += ( data[ p ] != d[ p ] );
					sum += ( checksum != tmp );
					if( sum < Min ) 
					{
						Min = sum;
						for( int p = 6; p < 14; p++ )
							ans[ p ] = d[ p ] + '0';
						ans[ 17 ] = ( d[ 17 ] == 10 ? 'X' : d[ 17 ] + '0' );
					}
				}
			}
		}
		memcpy( mon, m, sizeof( m ) );
		for( int j = 1; j <= 3; j++ )
		{
			for( int k = 1; k <= mon[ j ]; k++ )
			{
				int tmp = compute1( 2011, j, k );
				int sum = 0;
				for( int p = 6; p < 14; p++ )
					sum += ( data[ p ] != d[ p ] );
				sum += ( checksum != tmp );
				if( sum < Min ) 
				{
					Min = sum;
					for( int p = 6; p < 14; p++ )
						ans[ p ] = d[ p ] + '0';
					ans[ 17 ] = ( d[ 17 ] == 10 ? 'X' : d[ 17 ] + '0' );
				}
			}
		}
		for( int k = 1; k <= 2; k++ )
		{
			int tmp = compute1( 2011, 4, k );
			int sum = 0;
			for( int p = 6; p < 14; p++ )
				sum += ( data[ p ] != d[ p ] );
			sum += ( checksum != tmp );
			if( sum < Min ) 
			{
				Min = sum;
				for( int p = 6; p < 14; p++ )
					ans[ p ] = d[ p ] + '0';
				ans[ 17 ] = ( d[ 17 ] == 10 ? 'X' : d[ 17 ] + '0' );
			}
		}
	}
	printf( "%s\n", ans );
}

int main(int argc, char *argv[])
{
	int n, cas;
	// init( );
	scanf( "%d", &cas );
	while( cas-- )
	{
		scanf( "%s", buf );
		solve( );
	}
	return 0;
}
