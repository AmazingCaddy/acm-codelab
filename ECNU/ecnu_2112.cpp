// 解答树，DFS搜索减枝
#include<iostream>
#include<algorithm>
#define MAXN 102
using namespace std;
struct node
{
	double time,val;
	bool operator<( const node &b )
	{
		return val/time > b.val/b.time;
	}
};
struct STACK
{
	double time,val;
	int m;
};
node a[MAXN];
STACK stack[MAXN];
int top,n;
double L;

double f( double t, int m )
{
	if( m==n || t==0 )return 0;
	else if( t>=a[m+1].time )
		return ( f( t-a[m+1].time, m+1 )+a[m+1].val );
	else return ( t*a[m+1].val/a[m+1].time );
}

double DFS( )
{
	double y=0;
	stack[0].time=0;
	stack[0].val=0;
	stack[0].m=1;
	top=0;
	if( a[1].time<=L )
	{
		stack[++top].time=a[1].time;
		stack[top].val=a[1].val;
		stack[top].m=1;
	}
	while( top>=0 )
	{
		if( stack[top].m==n )
		{
			if( stack[top].val>y )
				y=stack[top].val;
			top--;
		}
		else if( stack[top].val+f( L-stack[top].time, stack[top].m ) > y )  
			//如果性价比最高的物品加入得到的值都比当前最优值小，那么减枝
		{
			stack[top].m=stack[top].m+1;
			{
				if( stack[top].time+a[stack[top].m].time <= L )
				{
					int aux=stack[top].m;
					stack[top+1].time=stack[top].time+a[aux].time;
					stack[top+1].val=stack[top].val+a[aux].val;
					stack[++top].m=aux;
				}
			}
		}
		else top--;
	}
	return y;
}

int main( )
{
	int t,i;
	double ans;
	scanf("%d",&t);
	while( t-- )
	{
		scanf("%d%lf",&n,&L);
		for( i=1; i<=n; i++ )
			scanf("%lf%lf",&a[i].time,&a[i].val);
		sort( a+1, a+n+1 );
		ans=DFS( );
		printf("%.lf\n",ans);
	}
	return 0;
}