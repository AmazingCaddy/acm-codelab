#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

bool isVo[ 300 ] = { 0 };
int c, l;
char alp[ 30 ];

int top = 1, totVo = 0, totNoVo = 0, totOut = 25000;
char stack[ 20 ] = { 'a' - 1 };
bool have[ 300 ] = { 0 };

void Dfs( void )
{
	if( top > l )
	{
		if( ( totVo > 0 ) && ( totNoVo > 1 ) )
		{
			stack[ top ] = 0;
			printf( "%s\n", stack + 1 );
			--totOut;
		}
		return;
	}
	for( int i = 0; i < c; ++i )
	{
		if( ( ! have[ alp[ i ] ] ) && ( alp[ i ] > stack[ top - 1 ] ) )
		{
			have[ alp[ i ] ] = true;
			if( isVo[ alp[ i ] ] )++totVo;
			else ++totNoVo;
			stack[ top++ ] = alp[ i ];
			Dfs( );
			if( totOut <= 0 )return;
			--top;
			if( isVo[ alp[ i ] ] )--totVo;
			else --totNoVo;
			have[ alp[ i ] ] = false;
		}
	}
}

int main( )
{
	int i;
	scanf("%d%d",&l,&c);
	for( i = 0; i < c; ++i )
		scanf("%1s", alp + i );
	sort( alp, alp + c );
	isVo[ 'a' ] = isVo[ 'o' ] = isVo[ 'e' ] = isVo[ 'i' ] = isVo[ 'u' ] = true;
	Dfs( );
	return 0;
}