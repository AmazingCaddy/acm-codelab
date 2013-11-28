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
const int P = 65521;

struct Hash{
    int k, v, nt;//key, value, next;
}hash[maxn << 1];

int flg[maxn],top,idx;

int f(int key){//保证hash值在[0, maxn)之间
	// hash函数
	if( key < 0 ) key = -key;
	return key % P;
}
void hashInit(){
	top = maxn; ++idx; 
}
void ins(int key ){
    int p = f( key ); int buf = p;
    if(flg[p] != idx){
        flg[p] = idx;
        hash[p].nt = -1;
        hash[p].k = key;
        hash[p].v = 1;
        return;
    }
    while(p != -1){
        if(hash[p].k == key){
        	// do some thing
			hash[ p ].v++;
			return;
        }
        p = hash[p].nt;
    }
    p = buf;
    hash[top].nt = hash[p].nt;
    hash[top].v = 1;
    hash[top].k = key;
    hash[p].nt = top++;
}

int find(int key )
{
    int p = f( key );
    if(flg[p] != idx) return 0;
    while(p != -1){
        if(hash[p].k == key){
         	return hash[p].v;
        }
        p = hash[p].nt;
    }
    return 0;
}
/*-------------------------HASH--END-------------------------------*/

int X[ 105 ], sum;

int pro( int n ) { return n * n * n; }
void init( )
{
	for( int i = 0, j = 0; i < 101; i++ )
		if( i != 50 ) X[ j++ ] = pro( i - 50 );
}

void calleft( int a, int b, int c )
{
	sum = 0;
	for( int i = 0; i < 100; i++ )
		for( int j = 0; j < 100; j++ )
			for( int k = 0; k < 100; k++ )
				sum += find( -a * X[ i ] - b * X[ j ] - c * X[ k ] );
}

void calright( int a, int b )
{
	for( int i = 0; i < 100; i++ )
		for( int j = 0; j < 100; j++ )
			ins( a * X[ i ] + b * X[ j ] );
}

int main(int argc, char *argv[])
{
	int x1, x2, x3, x4, x5;
	init( );
	while( scanf("%d%d%d%d%d",&x1,&x2,&x3,&x4,&x5) != EOF )
	{
		hashInit( );
		calright( x4, x5 );
		calleft( x1, x2, x3 );
		printf("%d\n",sum);
	}
	return 0;
}
