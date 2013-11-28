#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 100010;

char a[maxn], b[maxn], c[maxn<<1];
int n, m;

int find( )
{
	int len = m << 1;
	for( int i = 1; i < len; i++ )
	{
		for( int j = 0; j < m; j++, i++ )
		{
			if( b[j] < b[i%m] ) return i - j;
			if( b[j] > b[i%m] ) break;
		}
	}
	return m;
}

int solve( )
{
	int i = 0, j = 0;
	int lim = find( );
	for( i = 0; i < n; i++ )
	{
		for( j = 0; j < lim; j++, i++ )
		{
			if( b[j] < a[i] ) return i - j;
			if( b[j] > a[i] ) break;
		}
		if( j == lim ) i--;
	}
	return n;
}

int main( )
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	while( scanf("%s %s",a,b) != EOF )
	{
		n = strlen( a );
		m = strlen( b );
		int k = solve( );
		for( int i = 0; i < k; i++ )
			putchar( a[i] );
		printf("%s",b);
		for( int i = k; i < n; i++ )
			putchar( a[i] );
		printf("\n");
	}
	return 0;
}
