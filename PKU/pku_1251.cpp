#include<iostream>
#define MAXN 27
#define MAXINT 10000
using namespace std;
int prim( int cost[][MAXN], int n, int u )
{
	int lowcost[MAXN],min,closest[MAXN];
	int i,j,k,sum;
	for( i=0; i<n; i++ )
	{
		lowcost[i]=cost[u][i];
		closest[i]=u;
	}
	sum=0;
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
		lowcost[k]=0;
		sum+=min;
		for( j=0; j<n; j++ )
		{
			if( cost[k][j]!=0 && cost[k][j]<lowcost[j] )
			{
				lowcost[j]=cost[k][j];
				closest[j]=k;
			}
		}
	}
	return sum;
}

int main()
{
	int cost[MAXN][MAXN];
	int t,n,i,j,value;
	char ch1,ch2;
	while( cin>>n && n )
	{
		for( i=0; i<n; i++ )
		{
			for( j=0; j<n; j++ )
			{
				if( j==i )cost[i][j]=0;
				else cost[i][j]=cost[j][i]=MAXINT;
			}
		}
		for( i=0; i<n-1; i++ )
		{
			cin>>ch1>>t;
			for( j=0; j<t; j++ )
			{
				cin>>ch2>>value;
				cost[ch1-'A'][ch2-'A']=cost[ch2-'A'][ch1-'A']=value;
			}
		}
		printf("%d\n",prim( cost, n, 0 ));
	}
	return 0;
}
