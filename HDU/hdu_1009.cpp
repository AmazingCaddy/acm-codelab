#include<iostream>
#include<algorithm>
#define MAXN 1002
using namespace std;
const double eps = 1e-10;
struct node
{
	double j,f;
	bool operator<( const node & b )
	{
		return j/f>b.j/b.f;
	}
};
node a[MAXN];

int main( )
{
	int i,m,n;
	double ans,sum;
	while( 1 )
	{
		scanf("%d%d",&m,&n);
		if( m==-1 && n==-1 )break;
		for( i=0; i<n; i++ )
			scanf("%lf%lf",&a[i].j,&a[i].f);
		sort( a, a+n );
		sum=m;ans=0;
		for( i=0; i<n; i++ )
		{
			if( sum>=a[i].f )ans+=a[i].j;
			else
			{
				ans+=a[i].j/a[i].f*sum;
				break;
			}
			sum-=a[i].f;
		}
		printf("%.3lf\n",ans);
	}
	return 0;
}