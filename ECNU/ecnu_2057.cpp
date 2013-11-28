#include<iostream>
#include<algorithm>
#include<cmath>
#define MAXN 50005
using namespace std;
int a[MAXN];
bool compare( const int a, const int b )
{
	return abs(a)<abs(b);
}

int main( )
{
	int t,n,i,ans;
	scanf("%d%d",&t,&n);
	for( i=0; i<n; i++ )
		scanf("%d",&a[i]);
	sort( a, a+n, compare );
	t-=abs(a[0]);
	ans=0;
	for( i=1; i<=n && t>0; i++ )
	{
		ans++;
		t-=abs( a[i]-a[i-1] );
	}
	printf("%d\n",ans);
	return 0;
}