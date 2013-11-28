#include<iostream>
using namespace std;
int main( )
{
	int n,m,k,s,i;
	while( 1 )
	{
		scanf("%d%d%d",&n,&k,&m);
		if( n==0 && m==0 && k==0 )break;
		s=0;
		for( i=2; i<=n-1; i++ )
			s=(s+k)%i;
		printf("%d\n",(s+m)%n+1);
	}
	return 0;
}