////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 546711990
////Nickname: AmazingCaddy
////Run ID: 
////Submit time: 2010-04-16 18:12:18
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1097
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
typedef __int64 LL;
int num[10][7]={{1,0},{1,1},{4,6,2,4,8},{4,1,3,9,7},{2,6,4},
                {1,5},{1,6},{4,1,7,9,3},{4,6,8,4,2},{2,1,9}};
int main( )
{
	int a,b,ans;
	while( scanf("%d%d",&a,&b) != EOF )
	{
		ans = a % 10;
		ans = num[ans][b%num[ans][0]+1];
		printf("%d\n",ans);
	}
	return 0;
}