////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 546711990
////Nickname: AmazingCaddy
////Run ID: 
////Submit time: 2010-04-09 21:39:05
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1050
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:292KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main( )
{
	int n,num,temp,i,j,max;
	int a[200][2],b[201];
	cin>>n;
	while(n--)
	{
		cin>>num;
		memset( b, 0, sizeof(b) );
		for( i=0; i<num; i++ )
		{
			scanf("%d%d",&a[i][0],&a[i][1]);
			if( a[i][0]>a[i][1] )
			{
				temp=a[i][0];
				a[i][0]=a[i][1];
				a[i][1]=temp;
			}
		}
		for( i=0; i<num; i++ )
			for( j=(a[i][0]+1)/2; j<=(a[i][1]+1)/2; j++ )
				b[j]++;
		max=0;
		for( i=1; i<=200; i++ )
			if( b[i]>max ) 
				max=b[i];
		printf("%d\n",max*10);
	}
	return 0;
}
