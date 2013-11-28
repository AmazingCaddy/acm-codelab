#include<stdio.h>
int best, sum, s[22], n, m;
void ser( int d, int sum )
{
	if( sum >= m && sum < best )
		best = sum;
	if( d == n || sum >= best ) return;
	ser( d + 1, sum + s[ d ] );
	ser( d + 1, sum );
}
int main()
{
	int i;
	scanf( "%d%d", &n, &m );
	for( i = 0; i < n; i++ )
		scanf( "%d", &s[ i ] );
	best = 1 << 30;
	ser( 0, 0 );
	printf( "%d\n", best - m );
}
