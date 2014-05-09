//  一个humble数的{2，3，5，7}的积一定是一个humble，那么找出他们其中最小的作为新的humble。
//  为了加快搜索过程，可以使用一个素数集大小的数组记录这个素数与
//  某个humble的积<=当前最大humble的最大的位置，这样可以过滤掉小的数，
//  而且这个最大的humble的位置的下一个数和这个素数的乘积就是这个素数能产生的
//  最小的未生成的humble，比较每个素数能产生的最小的humble，选一个最小的作为新的humble
 
#include <iostream>
using namespace std;
const int INF=2000000000;
 
int main( )
{
	int num[5842] = { 1 };
	int a[4] = { 0 };
	int prime[4] = { 2, 3, 5, 7 };
	int min, count = 0, i,n;    
	for( count = 1; count < 5842; count++ )
	{
		for( i = 0; i < 4; i++ )
			if( num[a[i]] * prime[i] <= num[count-1] )
				a[i]++;
		min=2000000001;
		for( i = 0; i < 4; i++ )
			if( prime[i] * num[a[i]] < min )
				min = prime[i] * num[a[i]];
		num[count] = min;
	}
	while( scanf("%d",&n) && n )
	{
		if( n % 10 == 1 && n % 100 != 11 )
			printf("The %dst humble number is %d.\n",n,num[n-1]);
		else if( n % 10 == 2 && n % 100 != 12 )
			printf("The %dnd humble number is %d.\n",n,num[n-1]);
		else if( n % 10 == 3 && n % 100 != 13 )
			printf("The %drd humble number is %d.\n",n,num[n-1]);
		else
			printf("The %dth humble number is %d.\n",n,num[n-1]);
	}    
}