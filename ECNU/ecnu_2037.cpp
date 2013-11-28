#include<iostream>
#define MAXN 30003
using namespace std;
const int INF=1000000;
int g[MAXN];
int main( )
{
	int n,i,x,t,min;
	scanf("%d",&n);
	g[0]=0;
	for( i=1; i<=n; i++ )
	{
		scanf("%d",&x);
		if( x==1 )g[i]=g[i-1]+1;
		else g[i]=g[i-1];
	}
	min=INF;
	for( i=0; i<=n; i++ )
		if( (t=i-g[i]+g[n]-g[i])<min )
			min=t;
	printf("%d\n",min);
	return 0;
}