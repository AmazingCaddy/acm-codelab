//求最大子段和,复杂度O(n)
//传入串长n 和内容list[]
//返回最大子段和,重载返回子段位置(maxsum=list[start]+...+list[end])
//可更改元素类型
#include<iostream>
#define MAXN 100002
using namespace std;
typedef int elem_t;
elem_t a[MAXN];
elem_t maxsum( int n, elem_t* list, int& start, int& end )
{
	elem_t ret,sum=0;
	int s,i;
	for( ret=list[start=end=s=i=0]; i<n; i++, s=( sum>=0?s:i ) )//有多个解时，求出最前面的
		if( ( sum=( sum>=0?sum:0 )+list[i] ) > ret )
			ret=sum,start=s,end=i;
	return ret;
}

int main( )
{
	int i,ans,n,t,start,end,k=1;
	scanf("%d",&t);
	while( t-- )
	{
		scanf("%d",&n);
		for( i=0; i<n; i++ )
			scanf("%d",&a[i]);
		ans=maxsum( n, a, start, end );
		printf("Case %d:\n%d %d %d\n",k++,ans,start+1,end+1);
		if( t )printf("\n");
	}
}