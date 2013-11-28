// ans=((p-1)^n+(-1)^n(p-1))/p;

#include<iostream>
using namespace std;

__int64 pow_mod( __int64 a, __int64 n, __int64 pp )
{
	__int64 g=a,ret=1;
	while( 1 )
	{
		if( n&1 ) ret=(ret*g)%pp;
		g=(g*g)%pp;
		n>>=1;
		if( n==0 )break;
	}
	return ret;
}

int main( )
{
	__int64 p,n,ans,pp;
	while( scanf("%I64d%I64d",&p,&n) && ( p || n ) )
	{
		pp=2005*p;
		ans=pow_mod( p-1, n, pp );
		ans=(ans+(n%2==0?1:-1)*(p-1))%pp;
		ans/=p;
		printf("%I64d\n",ans);
	}
	return 0;
}