/*
	author: AmazingCaddy
	time: 2011/4/1  22:47
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

map< string, int > cnt;

char buf[ 20 ];

int main(int argc, char *argv[])
{
	int n;
	while( scanf( "%d", &n ) && n )
	{
		cnt.clear( );
		for( int i = 0; i < n; i++ )
		{
			scanf( "%s", buf );
			cnt[ buf ]++;
		}
		int m = 0;
		string ans;
		for( map<string, int>::iterator it = cnt.begin(); it != cnt.end(); it++ )
			if( it->second > m )
				m = it->second, ans = it->first;
		cout << ans << "\n";
	}
	return 0;
}
