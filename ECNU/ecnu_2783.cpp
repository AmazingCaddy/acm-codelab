#include<iostream>
#include<cmath>
#define MAXN 3003
int main( )
{
	bool vis[MAXN];
	int n,t,i,a,b;
	scanf("%d",&t);
	while( t-- )
	{
		scanf("%d",&n);
		memset( vis, false, sizeof(vis) );
		scanf("%d",&a);
		for( i=1; i<n; i++ )
		{
			scanf("%d",&b);
			vis[abs(b-a)]=true;
			a=b;
		}
		for( i=1; i<n; i++ )
			if( !vis[i] )break;
		if( i==n )printf("Jolly\n");
		else printf("Not jolly\n");
	}
	return 0;
}