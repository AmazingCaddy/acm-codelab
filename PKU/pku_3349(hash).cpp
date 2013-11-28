#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <complex>
#include <queue>
using namespace std;

/*--------------------------HASH-----------------------------------*/
const int maxn = 65536;//hash size
const int p = 65521;
struct snow
{
	int fl[ 6 ];
};
struct Hash
{
	snow s;
    int v, nt;		//key, value, next;
}hash[maxn << 1];

int flg[maxn], top, idx;

int cmp( const snow & s, const snow & t )
{
	int f[ 12 ], g[ 12 ], j;
	for( int i = 0; i < 6; i++ )
		f[ i ] = s.fl[ i ], f[ i + 6 ] = s.fl[ i ];
	for( int i = 0; i < 12; i++ )
		g[ i ] = f[ 11 - i ];
	for( int i = 0; i < 6; i++ )
	{
		for( j = 0; j < 6; j++ )
			if( f[ i + j ] != t.fl[ j ] ) break;
		if( j == 6 ) return 1;
	}
	for( int i = 0; i < 6; i++ )
	{
		for( j = 0; j < 6; j++ )
			if( g[ i + j ] != t.fl[ j ] ) break;
		if( j == 6 ) return 1;
	}
	return 0;
}

//保证hash值在[0, maxn)之间
int f( const snow & s )
{
	// hash函数
	int sum = 0;
	for( int i = 0; i < 6; i++ )
		sum += s.fl[ i ];
	return sum % p;
}

void hashInit( )
{
	top = maxn;	++idx; 
}

int ins( const snow &s )
{
    int p = f( s ); int buf = p;
    if(flg[p] != idx)
	{
        flg[p] = idx;
        hash[p].nt = -1;
        hash[p].s = s;
        return 0;
    }
    while(p != -1)
	{
        if( cmp( hash[p].s, s ) )
		{
        	// do some thing
			return 1;
        }
        p = hash[p].nt;
    }
    p = buf;
    hash[top].nt = hash[p].nt;
    hash[top].s = s;
    hash[p].nt = top++;
	return 0;
}
/*
bool find( const snow & s )
{
    int p = f( s );
    if( flg[p] != idx ) return false;
    while(p != -1)
	{
        if(hash[p].k == key)
		{
         	val = hash[p].v;
         	return true;
        }
        p = hash[p].nt;
    }
    return false;
}
*/
/*-------------------------HASH--END-------------------------------*/

int main(int argc, char *argv[])
{
	int n, flag;
	snow s;
	while( scanf("%d",&n) != EOF )
	{
		hashInit( );
		flag = 0;
		for( int i = 0; i < n; i++ )
		{
			for( int j = 0; j < 6; j++ )
				scanf("%d",&s.fl[j]);
			if( flag ) continue;
			if( ins( s ) ) flag = 1;
		}
		if( flag ) printf("Twin snowflakes found.\n");
		else printf("No two snowflakes are alike.\n");
	}
	return 0;
}
