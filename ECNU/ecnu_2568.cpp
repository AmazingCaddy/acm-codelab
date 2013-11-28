#include<stdio.h>
int main()
{
	int t,count,a,b,sum;
	scanf("%d",&t);
	while( t-- )
	{
		scanf("%d%d",&a,&b);
		sum=a+b;
		count=0;
		while( sum )
		{
			count++;
			sum=sum/10;
		}
		printf("%d\n",count);
	}
	return 0;
}
			