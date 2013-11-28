#include<iostream>
#define MAXN 500
#define MAXINT 1000000
using namespace std;
int prim( int cost[][MAXN], int n, int u )
{
	int lowcost[MAXN],min,closest[MAXN];
	int i,j,k,sum,max;
	for( i=0; i<n; i++ )
	{
		lowcost[i]=cost[u][i];
		closest[i]=u;
	}
	max=0;
	for( i=0; i<n-1; i++ )
	{
		min=MAXINT;
		for( j=0; j<n; j++ )
		{
			if( lowcost[j]!=0 && lowcost[j]<min )
			{
				min=lowcost[j];
				k=j;
			}
		}
		if( min>max )max=min;
		lowcost[k]=0;
		for( j=0; j<n; j++ )
		{
			if( cost[k][j]!=0 && cost[k][j]<lowcost[j] )
			{
				lowcost[j]=cost[k][j];
				closest[j]=k;
			}
		}
	}
	return max;
}

int main()
{
	int cost[MAXN][MAXN];
	int n,i,j,t;
	scanf("%d",&t);
	while( t-- )
	{
		scanf("%d",&n);
		for( i=0; i<n; i++ )
			for( j=0; j<n; j++ )
				scanf("%d",&cost[i][j]);
		printf("%d\n",prim( cost, n, 0 ));
	}
	return 0;
}
