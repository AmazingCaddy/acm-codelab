/*
	author: AmazingCaddy
	time:	
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <complex>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <map>
using namespace std;

const int maxn = 20;
map<string, string> hello;
char buf[ maxn ];

int main(int argc, char *argv[]) {
	hello[ "HELLO" ] = "ENGLISH";
	hello[ "HOLA" ] = "SPANISH";
	hello[ "HALLO" ] = "GERMAN";
	hello[ "BONJOUR" ] = "FRENCH";
	hello[ "CIAO" ] = "ITALIAN";
	hello[ "ZDRAVSTVUJTE" ] = "RUSSIAN";
	int t = 1;
	while( scanf( "%s", buf ) != EOF ) {
		if( strcmp( buf, "#" ) == 0 ) {
			break;
		}
		printf( "Case %d: ", t++ );
		if( hello.find( buf ) != hello.end( ) ) {
			cout << hello[ buf ] << endl;
		}
		else {
			printf( "UNKNOWN\n" );
		}
	}
	return 0;
}
