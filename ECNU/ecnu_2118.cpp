//#include<iostream>
//#include<cmath>
//#define MAXN 10000002
//using namespace std;
//bool vis[MAXN];
//int p[665000];
//int len,cnt;
//__int64 ans,a[65],b[65];
//
//void prime( )
//{
//	__int64 i,j,k;
//	len=0;
//	memset( vis, false, sizeof( vis ) );
//	for( i=2, k=4; i < MAXN; ++i, k+=i+i-1 )
//	{
//		if( !vis[i] )
//		{
//			p[len++]=i;
//			if( k < MAXN )
//			{
//				for( j=k; j < MAXN; j+=i )
//					vis[j]=true;
//			}
//		}
//	}
//}
//
//__int64 euler( __int64 n )
//{
//	__int64 i,j;
//	__int64 phi=n;
//	for( i=0; (__int64)p[i]*p[i]<=n; i++ )
//	{
//		if( n%p[i]==0 )
//		{
//			while( !(n%p[i]) )
//				n/=p[i];
//			phi=phi/p[i]*(p[i]-1);
//		}
//	}
//	if( n>1 )phi=phi/n*(n-1);
//	return phi;
//}
//
//void DFS( int depth, __int64 tem )
//{
//	int i;
//	if( depth==cnt )
//	{
//		ans+=euler( tem+1 );
//		return;
//	}
//	__int64 temp=1;
//	for( i=0; i<=b[depth]; i++ )
//	{
//		DFS( depth+1, tem * temp );
//		temp*=a[depth];
//	}
//}
//
//int main( )
//{
//	int i,j,k,t;
//	__int64 n;
//	double up;
//	prime( );
//	scanf("%d",&t);
//	while( t-- )
//	{
//		scanf("%I64d",&n);
//		if( n==0 )printf("%d\n",0);
//		else
//		{
//			j=0;
//			for( i=0; (__int64)p[i] * p[i] <= n; i++ )
//			{
//				if( n%p[i]==0 )
//				{
//					for( b[j]=0; n%p[i]==0; ++b[j], n/=p[i] );
//					a[j++]=p[i];
//				}
//			}
//			if( n>1 ) b[j]=1, a[j++]=n;
//			ans=0;
//			cnt=j;
//			DFS( 0, 1 );
//			printf("%I64d\n",ans);
//		}
//	}
//	return 0;
//}