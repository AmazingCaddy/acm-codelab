#include<iostream>
using namespace std;
const int maxn = 500003;
int a[maxn], d3[maxn];
int len3;
int search3( int len, int n ) //不下降的二分函数
{
	int low = 1, high = len, mid;
	while( low <= high )
	{
		mid = ( low + high ) / 2;
		if( n >= d3[mid] ) low = mid + 1;
		else if( n < d3[mid] ) high = mid - 1;
	}
	return low;
}

void LNDS( int b[], int n ) //最长不下降子序列
{
	int i,t;
	len3 = 1;
	d3[len3] = a[0];
	for( i = 1; i < n; i++ )
	{
		if( a[i] >= d3[len3] ) d3[++len3] = a[i];
		else 
		{
			t = search3( len3, a[i] );
			d3[t] = a[i];
		}
	}
}



int main( )
{
	int i, n, k = 1, x, y;
	while( scanf("%d",&n) != EOF )
	{
		for( i = 0; i < n; i++ )
		{
			scanf("%d%d",&x,&y);
			a[x-1] = y;
		}
		len3 = 0;
		LNDS( a, n );
		printf("Case %d:\nMy king, at most %d road",k++,len3);  
		if( len3 != 1 )printf("s");  
		printf(" can be built.\n\n");
	}
	return 0;
}