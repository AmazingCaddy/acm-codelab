#include<iostream>
#define MAXN 100002
using namespace std;
int begin[MAXN],end[MAXN];
int main( )
{
	int n,i,num;
	int a,b;
	while( scanf("%d",&n) && n )
	{
		memset( end, 0, sizeof(end) );
		memset( begin, 0, sizeof(begin) );
		for( i=1; i<=n; i++ )
		{
			scanf("%d%d",&a,&b);
			begin[a]++;
			end[b]++;
		}
		num=0;
		for( i=1; i<=n; i++ )
		{
			if( i!=1 )printf(" ");
			num+=begin[i];
			printf("%d",num);
			num-=end[i];
		}
		printf("\n");
	}
	return 0;
}