/*
    author: AmazingCaddy
    time: 17/05/2011 21:29:31 
*/
#include <iostream>
#include <complex>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int maxn = 10004;
char buf[ maxn ];

int main( int ac, char * av[ ] )
{
	while( 1 )
	{
		scanf( "%s", buf );
		if( strcmp( buf, "end" ) == 0 ) break;
		int len = strlen( buf );
		int cnt1 = 0, cnt2 = 0, cnt3 = 0, flag = 0;
		for( int i = 0; i < len; i++ )
		{
			if( buf[ i ] == 'a' || buf[ i ] == 'e' || buf[ i ] == 'i' || buf[ i ] == 'o' || buf[ i ] == 'u' )
			{
				cnt1++, cnt2++;
				cnt3 = 0;
				if( cnt2 == 3 ) { flag = 1; break; }
			}
			else 
			{
				cnt3++;
				cnt2 = 0;
				if( cnt3 == 3 ) { flag = 1; break; }
			}
			if( i > 0 && buf[ i ] == buf[ i - 1 ] && buf[ i ] != 'e' && buf[ i ] != 'o' )
			{
				//cout << "OK" << endl;
				flag = 1;
				break;
			}
		}
		if( cnt1 == 0 )
		{
			printf( "<%s> is not acceptable.\n", buf );
			continue;
		}
		if( flag ) printf( "<%s> is not acceptable.\n", buf );
		else printf( "<%s> is acceptable.\n", buf );
	}
	return 0;
}
