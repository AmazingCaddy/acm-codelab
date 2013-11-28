/*
	author: AmazingCaddy
	time: 2011/5/13  18:26
	树状数组
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
#define Lowbit(x) ((x)&(-(x)))
using namespace std;
const int maxn = 50004;
int num[ maxn ];
int idxMax[ maxn ], idxMin[ maxn ];
int n, q;
int Max( int a, int b ) { return ( a > b ? a : b ); }
int Min( int a, int b ) { return ( a < b ? a : b ); }
void InitMax( int n )
{
	for( int i = 1; i <= n; i++ )
	{
		idxMax[ i ] = num[ i ];
		for( int j = 1; j < Lowbit( i ); j << = 1 )
			idxMax[ i ] = Max( idxMax[ i ], idxMax[ i - j ] );
	}
}

void InitMin( int n )
{
	for( int i = 1; i <= n; i++ )
	{
		idxMin[ i ] = num[ i ];
		for( int j = 1; j < Lowbit( i ); j <<= 1 )
			idxMin[ i ] = Min( idxMin[ i ], idxMin[ i - j ] );
	}
}

int QueryMax( int l, int r )
{
    int ans = num[ r ];
    while( 1 )
	{
		ans = Max( ans, num[ r ] );
		if( r == l ) break;
		for( r -= 1; r - l >= Lowbit( r ); r -= Lowbit( r ) )
			ans = Max( ans, idxMax[ r ] );
	}
	return ans;
}

int QueryMin( int l, int r )
{
	int ans = num[ r ];
	while( 1 )
	{
		ans = Min( ans, num[ r ] );
		if( r == l ) break;
		for( r -= 1; r - l >= Lowbit( r ); r -= Lowbit( r ) )
			ans = Min( ans, idxMin[ r ] );
	}
	return ans;
}

void Modify( int p, int v, int n )
{
    num[ p ] = v;
	idx[ p ] = v;
    for( int i = p; i <= n; i += Lowbit( i ) )
	{
        idx[ i ] = Max( idx[ i ], v );
        for( int j = 1; j < Lowbit( i ); j <<= 1 )
            idx[ i ] = Max( idx[ i ], idx[ i - j ] );
    }
}

/* 此代码有问题
void Modify(int p,int v,int n){
    num[p]=v;
    for(int i=p;i<=n;i+=Lowbit(i)){
        idx[i]=MAX(idx[i],v);
        for(int j=1;j<Lowbit(i);j<<=1){
            idx[i]=MAX(idx[i],idx[i-j]);
        }
    }
}
*/

int getnum( )
{
	int i, j;
	char c;
	while( ' '==(c=getchar()) || c=='\n');
	for( j = c-'0'; '0' <= (c=getchar()) && c <= '9'; j = j*10 + c-'0' );
	return j;
}

int main(int argc, char *argv[])
{
	int l, r;
	scanf( "%d%d", &n, &q );
	for( int i = 1; i <= n; i++ )
		//scanf( "%d", &num[ i ] );
		num[ i ] = getnum( );
	InitMin( n );
	InitMax( n );
	for( int i = 0; i < q; i++ )
	{
		l = getnum( );
		r = getnum( );
		//scanf( "%d%d", &l, &r );
		printf( "%d\n", QueryMax( l, r ) - QueryMin( l, r ) );
	}
	return 0;
}
