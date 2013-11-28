////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 546711990
////Nickname: AmazingCaddy
////Run ID: 
////Submit time: 2010-04-09 19:57:11
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1051
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:340KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstdlib>
#define MAXN 5001
using namespace std;
struct node
{
	int l,w;
};

node stick[MAXN];
bool vis[MAXN];
int compare( const void * a, const void * b )
{
	node *p,*q;
	p=(node*)a;q=(node*)b;
	if( p->l == q->l )return p->w-q->w;
	else return p->l-q->l;
}

int main( )
{
	int t,n,i,j,count;
	cin>>t;
	while( t-- )
	{
		cin>>n;
		for( i=0; i<n; i++ )
			scanf("%d%d",&stick[i].l,&stick[i].w);
		qsort( stick, n, sizeof(node), compare );
		memset( vis, false, sizeof(vis) );
		count=0;
		for( i=0; i<n; i++ )
		{	
			if( !vis[i] )
			{
				int maxl=stick[i].l,maxw=stick[i].w;
				vis[i]=true;
				for( j=i+1; j<n; j++ )
				{
					if( stick[j].l>=maxl && stick[j].w>=maxw && !vis[j] )
					{
						maxl=stick[j].l;
						maxw=stick[j].w;
						vis[j]=true;
					}
				}
				count++;
			}
		}
		printf("%d\n",count);
	}
	return 0;
}