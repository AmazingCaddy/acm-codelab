//  f(n) = (n%9==0) ? 9 : n%9

#include<iostream>
#define MAXN 1001
using namespace std;

int main( )
{
	int i,n,k,sum,ans;
	int a[MAXN];
	scanf("%d",&k);
	while( k-- )
	{
		scanf("%d",&n);
		for( i=0; i<n; i++ )
			scanf("%d",&a[i]);
		sum=(a[n-1]+1)%9;
		for( i=n-2; i>=0; i-- )
			sum=(sum*(a[i]%9))%9+1;
		sum=sum-1;
		if( sum%9==0 )ans=9;
		else ans=sum%9;
		printf("%d\n",ans);
	}
	return 0;
}