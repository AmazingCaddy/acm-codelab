////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 546711990
////Nickname: AmazingCaddy
////Run ID: 
////Submit time: 2010-03-19 13:58:12
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1001
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
typedef __int64 LL;
int main( )
{
	LL n;
	while( scanf("%I64d",&n) != EOF )
		printf("%I64d\n\n",n*(n+1)/2);
	return 0;
}