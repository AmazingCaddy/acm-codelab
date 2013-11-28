#include <stdio.h>
#include <stdlib.h>

#define  N  1003

typedef struct
{
	int pid, time, wait;
}Node;

int cmp( const void * a, const void * b ){
	return ((Node*)a)->pid - ((Node*)b)->pid;
}

int main(){
	Node p[N];
	char cmd[30];
	int n, td, t, num, i;
	scanf( "%d", &td );
	for( t=1; t<=td; ++t ){
		if( t > 1 ){
			printf( "\n" );
		}
		printf( "test case %d:\n", t );
		n = 0;
		for( scanf( "%s", cmd ); cmd[1]=='e'; scanf( "%s", cmd ) ){
			scanf( "%d%d", &(p[n].pid), &(p[n].time) );
			p[n].wait = p[n].time;
			++n;
		}
		if( n > 0 ){
			qsort( p, n, sizeof(Node), cmp );
		}
		scanf( "%s%d", cmd, &num );
		while( num ){
			for( i=0; i<n; ++i ){
				if( --(p[i].wait) == 0 ){
					printf( "%d\n", p[i].pid );
					p[i].wait = p[i].time;
					if( --num == 0 ) break;
				}
			}
		}
	}
	return 0;
}
