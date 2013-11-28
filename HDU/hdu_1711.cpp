// KMP
#include<iostream>
#define MAXN 1000005
#define MAXM 10005
using namespace std;
int flink[MAXM];
int num[MAXM];
int NUM[MAXN];

void fail_link( int m )
{
	int j,k;
	flink[0]=-1;
	j=1;
	while( j < m )
	{
		k = flink[j-1];
		while( k != -1 && num[k] != num[j-1] )
			k = flink[k];
		flink[j] = k + 1;
		j++;
	}
}

int KMP( int n, int m )
{
	int i,j;
	i = 0, j = 0;
	while( i < n )
	{
		while( j != -1 && num[j] != NUM[i] )
			j = flink[j];
		if( j ==  m-1 ) return ( i - m + 1 );
		i++;
		j++;
	}
	return -2;
}

int main( )
{
	int i,n,m,t;
	scanf("%d",&t);
	while( t-- )
	{
		scanf("%d%d",&n,&m);
		for( i=0; i<n; i++ )
			scanf("%d",&NUM[i]);
		for( i=0; i<m; i++ )
			scanf("%d",&num[i]);
		fail_link( m );
		printf("%d\n",KMP( n, m ) + 1 );
	}
	return 0;
}