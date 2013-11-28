#include<iostream>
using namespace std;
typedef __int64 LL;
int num[10][7]={{1,0},{1,1},{4,6,2,4,8},{4,1,3,9,7},{2,6,4},
                {1,5},{1,6},{4,1,7,9,3},{4,6,8,4,2},{2,1,9}};
int main( )
{
	int n,t,ans;
	scanf("%d",&t);
	while( t-- )
	{
		scanf("%d",&n);
		ans = n % 10;
		ans = num[ans][n%num[ans][0]+1];
		printf("%d\n",ans);
	}
	return 0;
}

