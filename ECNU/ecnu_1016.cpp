#include<iostream>
#include<cmath>
#define MAXN 100002
#define eps 1e-5
using namespace std;
int a[MAXN],s[MAXN];
int n,f;

bool reach( double x )
{
	int i;
	double max1,max2;
	double b=s[f-1]-(f-1)*x;
	for( i=f; i<=n; i++ )
	{
		max1=b+a[i]-x;
		max2=s[i]-s[i-f]-f*x;
		b=max1>max2?max1:max2;
		if( b>=0 )return true;
	}
	return (b>=0);
}

int main( )
{
	int i,ans;
	double l,r,mid;
	scanf("%d%d",&n,&f);
	a[0]=0;
	r=0;
	for( i=1; i<=n; i++ )
	{
		scanf("%d",&a[i]);
		s[i]=s[i-1]+a[i];
		if( a[i]>r )r=a[i];
	}
	l=0;
	while( r-l>eps )
	{
		mid=(l+r)/2;
		if( reach(mid) ) l=mid;
		else r=mid;
	}
	ans=(mid+eps)*1000;
	printf("%d\n",ans);
	return 0;
}