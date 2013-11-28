/*
	author: AmazingCaddy
	time:	2011/9/22	20:30
	solve:	simulation
*/
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <complex>
#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;

const int maxn = 10005;
const int inf = 0x3fffffff;

int main(int argc, char *argv[]){
	string str;
	int cas;
	scanf( "%d", &cas );
	for( int t = 1; t <= cas; t++ ) {
		cin >> str;
		int len = str.length( ), i;
		for( i = 1; i < len; i++ ) {
			if( str[ i - 1 ] == '/' && str[ i ] == '/' ) {
				break;
			}
		}
		int k = i;
		printf( "Case #%d: ", t );
		for( int i = k + 1; i < len; i++ ) {
			if( str[ i ] == ':' || str[ i ] == '/' ) {
				break;
			}
			printf( "%c", str[ i ] );
		}
		printf( "\n" );
	}
	return 0;
}
