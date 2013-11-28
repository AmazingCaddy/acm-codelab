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

/*--------------------------HASH-----------------------------------*/
const int maxn = 65536;//hash size
const int P = 65521;

int a, b, c, d;

struct Hash{
    int k, nt; //key, value, next;
	int cnt; 
}hash[maxn << 1];

int flg[ maxn ], top, idx;

int f( int key ){//保证hash值在[0, maxn)之间
	return ( key % P + P ) % P;
	// hash函数
}
void hashInit( ){
	top = maxn; ++idx; 
}
void ins( int key )
{
    int p = f( key ); int buf = p;
    if( flg[ p ] != idx )
	{
        flg[ p ] = idx;
        hash[ p ].nt = -1;
        hash[ p ].k = key;
		hash[ p ].cnt = 1;
        return;
    }
    while( p != -1 )
	{
        if( hash[ p ].k == key )
		{
			hash[ p ].cnt++;
			return;
        	// do some thing
        }
        p = hash[ p ].nt;
    }
    p = buf;
    hash[ top ].nt = hash[ p ].nt;
    hash[ top ].k = key;
	hash[ top ].cnt = 1;
    hash[ p ].nt = top++;
}

int find( int key )
{
    int p = f( key );
    if( flg[ p ] != idx ) return 0;
    while( p != -1 )
	{
        if( hash[ p ].k == key )
		{
         	return hash[ p ].cnt;
        }
        p = hash[ p ].nt;
    }
    return 0;
}
/*-------------------------HASH--END-------------------------------*/

int main(int argc, char *argv[])
{
	idx = 0;
	while( scanf( "%d%d%d%d", &a, &b, &c, &d ) != EOF )
	{
		if( a < 0 && b < 0 && c < 0 && d < 0 )
		{
			printf( "0\n" );
			continue;
		}
		if( a > 0 && b > 0 && c > 0 && d > 0 )
		{
			printf( "0\n" );
			continue;
		}
		hashInit( );
		for( int i = 1; i <= 100; i++ )
			for( int j = 1; j <= 100; j++ )
				ins( a * i * i + b * j * j );
		int sum = 0;
		for( int i = 1; i <= 100; i++ )
			for( int j = 1; j <= 100; j++ )
					sum += find( -c * i * i - d * j * j );
		printf( "%d\n", sum * 16 );
	}
	return 0;
}
