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
using namespace std;

const int maxn = 14;
int g[ maxn ][ maxn ];

bool check( int p, int q )
{
	int vis[ 10 ];
	memset( vis, 0, sizeof( vis ) );
	for( int i = 0; i < 9; i++ )
	{
		vis[ g[ p ][ i ] ] = 1;
		vis[ g[ i ][ q ] ] = 1;
	}
	int ii = p / 3, jj = q / 3;
	for( int i = ii * 3; i < ii * 3 + 3; i++ )
		for( int j = jj * 3; j < jj * 3 + 3; j++ )
			vis[ g[ i ][ j ] ] = 1;
	int cnt = 0, k;
	for( int i = 1; i <= 9; i++ )
	{
		if( vis[ i ] ) cnt++;
		else k = i;
	}
	if( cnt < 8 ) return false;
	else
	{
		g[ p ][ q ] = k;
		return true; 
	}
	int m[ 4 ][ 4 ];
	cnt = 0;
	int ans = 0;
	for( k = 1; k <= 9; k++ )
	{
		memset( m, 0, sizeof( m ) );
		for( int i = ii * 3; i < ii * 3 + 3; i++ )
		{
			for( int j = 1; j <= 9; j++ )
			{
				if( g[ i ][ j ] == k )
				{
					int t = ii * 3;
					m[ i - t ][ 0 ] = m[ i - t ][ 1 ] = m[ i - t ][ 2 ] = 1;
				}
			}
		}
		for( int j = jj * 3; j < jj * 3 + 3; j++ )
		{
			for( int i = 1; i <= 9; i++ )
			{
				if( g[ i ][ j ] == k )
				{
					int t = jj * 3;
					m[ 0 ][ j - t ] = m[ 1 ][ j - t ] = m[ 2 ][ j - t ] = 1;
				}
			}
		}
		if( m[ p - ii * 3 ][ q - jj * 3 ] ) continue;
		int tmp = 0;
		for( int i = 0; i < 3; i++ )
			for( int j = 0; j < 3; j++ )
				if( m[ i ][ j ] == 1 ) tmp++;
		if( tmp == 8 ) cnt++, ans = k;
	}
	if( cnt != 1 ) return false;
	g[ p ][ q ] = k;
	return true;
}

int solve( )
{
	int cnt = 0;
	for( int i = 0; i < 9; i++ )
		for( int j = 0; j < 9; j++ )
			if( g[ i ][ j ] ) cnt++;
	int le = 81 - cnt;
	int ple = 81;
	while( le && le < ple )
	{
		int tmp = le;
		ple = le;
		for( int i = 0; i < 9; i++ )
		{
			for( int j = 0; j < 9; j++ )
			{
				if( g[ i ][ j ] == 0 )
				{
					if( check( i, j ) )tmp--;
				}
			}
		}
		le = tmp;
	}
	if( le == 0 ) return 1;
	return 0;
}

int main(int argc, char *argv[])
{
	int n;
	scanf( "%d", &n );
	for( int t = 0; t < n; t++ )
	{
		for( int i = 0; i < 9; i++ )
			for( int j = 0; j < 9; j++ )
				scanf( "%d", &g[ i ][ j ] );
		int flag = solve( );
		printf( "%d", flag );
	}
	printf( "\n" );
	return 0;
}
