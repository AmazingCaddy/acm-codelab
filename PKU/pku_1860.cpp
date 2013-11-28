#include<iostream>
#define MAXN 102
#define eps 1e-8
using namespace std;
struct node
{
	int u,v;
	double rate,com;
};
node E[MAXN<<1];
double dis[MAXN];
int N,M;
bool Bellman_Ford( int S, double V )
{
	int i,j,f;
	double t;
	for( i=0; i<=N; i++ )
		dis[i]=0.0;
	dis[S]=V;
	while( dis[S] <= V+eps )
	{
		f=0;
		for( j=0; j<M*2; j++ )
		{
			if( dis[E[j].v] + eps < ( t=( dis[E[j].u]-E[j].com )*E[j].rate ) )
			{
				f=1;
				dis[E[j].v]=t;
			}
		}
		if( !f ) // 不能再更新了 
			return( dis[S] > V+eps );
	}
	return true;
}

int main( )
{
	int i,S,a,b;
	double V,rab,rba,cab,cba;
	while( scanf("%d%d%d%lf",&N,&M,&S,&V) != EOF )
	{
		for( i=0; i<M*2; i++ )
		{
			scanf("%d%d%lf%lf%lf%lf",&a,&b,&rab,&cab,&rba,&cba);
			E[i].u=a,E[i].v=b,E[i].rate=rab,E[i++].com=cab;
			E[i].u=b,E[i].v=a,E[i].rate=rba,E[i].com=cba;
		}
		if( Bellman_Ford( S, V ) )printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}