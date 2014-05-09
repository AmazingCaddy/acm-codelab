//  每年只需要考虑以下四种情况就可以了
//  ssssdssssdss
//  sssddsssddss
//  ssdddssdddss
//  sddddsddddsd
//  注意最后的如果四个月都亏还不能满足题意，那么只能是5个月都亏了，也就是全年都是亏损的

#include<iostream>
using namespace std;
int main( )
{
	int s,d,ans;
	while( scanf("%d%d",&s,&d) != EOF )
	{
		if( 4*s-d<0 )ans=10*s-d*2;
		else if( 3*s-2*d<0 )ans=8*s-4*d;
		else if( 2*s-3*d<0 )ans=6*s-6*d;
		else if( s-4*d<0 )ans=3*s-9*d;
		else ans=-1;
		if( ans<0 )printf("Deficit\n");
		else printf("%d\n",ans);
	}
	return 0;
}