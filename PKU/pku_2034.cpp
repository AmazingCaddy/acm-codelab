/*
	author: AmazingCaddy
	time: 2011/3/12  13:51
*/
#include <cstdio>
#include <complex>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

const int maxn = 10100;

int p[ maxn ];
int x[ maxn ], use[ maxn ];
int n, m, d;

void prime( ) // p[ i ] = 1, means i is not a prime number
{
	int i, j, k;
	memset( p, 0, sizeof( p ) );
	p[ 0 ] = p[ 1 ] = 1;
	for( i = 2, k = 4; i < maxn; ++i, k += i + i - 1 )
		if( !p[ i ] && k < maxn )
			for( j = k; j < maxn; j += i ) p[ j ] = 1;
}

int check(int dep)
{
    int i, sum, cnt = 2;
    while( cnt <= d )
    {
        sum = 0;
        if( dep - cnt + 1 >= n )
        {
            for( i = dep; i >= dep - cnt + 1; i-- )
                sum += x[ i ];
            if( !p[ sum ] ) return 0;
        }
        cnt++;
    }
    return 1;
}

int flag;
void DFS( int dep )
{
	if( flag ) return;
	if( dep > m )
	{
		flag = 1;
		for( int i = n; i <= m; i++ )
		{
			if( i != n )printf( "," );
			printf( "%d", x[ i ] );
		}
		printf( "\n" );
		return;
	}
	for( x[ dep ] = n; x[ dep ] <= m; x[ dep ]++ )
	{
		if( flag ) return;
		if( use[ x[ dep ] ] ) continue;
		if( !check( dep ) ) continue;
		use[ x[ dep ] ] = 1;
		DFS( dep + 1 );
		use[ x[ dep ] ] = 0;
	}
}

int main(int argc, char *argv[])
{	
	prime( );
	//for( int i = 2; i < 100; i++ )
	//	if( !p[ i ] ) cout << i << endl;
	while( 1 )
	{
		scanf("%d %d %d", &n, &m, &d );
		if( m == 0 && n == 0 && d == 0 ) break;
        flag = 0;
        memset( use, 0, sizeof( use ) );
        DFS( n );
        if( !flag ) printf( "No anti-prime sequence exists.\n" );
    }
    return 0;
}
