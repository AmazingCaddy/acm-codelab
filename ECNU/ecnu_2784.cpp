#include<iostream>
using namespace std;
int main( )
{
	int t,a,ans;
	scanf("%d",&t);
	while( t-- )
	{
		scanf("%d",&a);
		if( a%2==1 )ans=a*(a-1);
		else ans=a*(a-2);
		printf("%d\n",ans);
	}
	return 0;
}