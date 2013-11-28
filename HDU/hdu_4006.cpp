/*
	author: AmazingCaddy
	time:	
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
#include <queue>
using namespace std;
typedef priority_queue< int, vector<int>, greater<int> > heap;
typedef long long ll;

heap minheap;

int main(int argc, char *argv[]) {
	int n, k, x;
	char op[ 10 ];
	while( scanf( "%d%d", &n, &k ) != EOF ) {
		while( !minheap.empty( ) ) {
			minheap.pop( );
		}
		for( int i = 0; i < n; i++ ) {
			scanf( "%s", op );
			if( op[ 0 ] == 'I' ) {
				scanf( "%d", &x );
				minheap.push( x );
				if( minheap.size( ) > k ) {
					minheap.pop( );
				}
			}
			else {
				printf( "%d\n", minheap.top( ) );
			}
		}
	}
	return 0;
}
