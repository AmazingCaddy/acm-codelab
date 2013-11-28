//二分搜索

#include<iostream>
#include<algorithm>
#define MAXN 100002
using namespace std;
const int INF=~(1<<31);
int a[MAXN],n;
int bin_search1( int k )
{
	int l=0,r=n-1,mid;
	while( l<=r )
	{
		mid=(l+r)>>1;
		if( a[mid]>=k ) r=mid-1;  //尽量往前移动，取到相同数的第一个数
		else l=mid+1;
	}
	return l;
}

int bin_search2( int k )
{
	int l=0,r=n-1,mid;
	while( l<=r )
	{
		mid=(l+r)>>1;
		if( a[mid]<=k )l=mid+1;   //尽量往后移动，取到相同数的最后一个数
		else r=mid-1;
	}
	return r;
}

int main( )
{
	int m,h,i,level,ans;
	while( scanf("%d",&n) != EOF )
	{
		for( i=0; i<n; i++ )
			scanf("%d",&a[i]);
		sort( a, a+n );
		scanf("%d",&m);
		for( i=0; i<m; i++ )
		{
			scanf("%d%d",&h,&level);
			switch( level )
			{
			case 1: ans=bin_search2( 100-h )-bin_search1( 0-h )+1;break;
			case 2: ans=bin_search2( 500-h )-bin_search1( 101-h )+1;break;
			case 3: ans=bin_search2( 2000-h )-bin_search1( 501-h )+1;break;
			case 4: ans=bin_search2( 10000-h )-bin_search1( 2001-h )+1;break;
			case 5: ans=bin_search2( 50000-h )-bin_search1( 10001-h )+1;break;
			case 6: ans=bin_search2( 200000-h )-bin_search1( 50001-h )+1;break;
			case 7: ans=bin_search2( INF-h )-bin_search1( 200001-h )+1;break;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}