#include <stdio.h>
#include <string.h>
#define MAXN 10000
char buf[MAXN];
int a[MAXN];
const int mod[20]={ 1, 1, 2, 6, 4, 2, 2, 4, 2, 8, 4, 4, 8, 4, 6, 8, 8, 6, 8, 2 };
int lastdigit( )
{
	int len , i, c, ret=1;
	len = strlen( buf );
	if( len == 1 ) return mod[ buf[0] - '0' ];
	for( i = 0; i < len; i++ ) a[i] = buf[ len-1-i ] - '0';
	for( ; len; len -= !a[ len-1 ] )
	{
		ret = ret * mod[ a[1] % 2 * 10 + a[0] ] % 5;
		for( c = 0, i = len-1; i >= 0; i-- )
			c = c * 10 + a[i], a[i] = c / 5, c %= 5;
	}
	return ret + ret % 2 * 5;
}

int main( )
{
	while( scanf("%s",buf) != EOF )
		printf("%d\n",lastdigit( ) );
}