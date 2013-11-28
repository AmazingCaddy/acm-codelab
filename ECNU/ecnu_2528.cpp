#include<stdio.h>
int main()
{
	int n,i,j;
	__int64 a[50],sum;
	a[0]=1;a[1]=2;
	for(i=2;i<50;i++)
	{
		sum=1;
		for(j=0;j<i;j++)
			sum*=2;
		a[i]=sum-a[i-1];
	}
	while(scanf("%d",&n)!=EOF)
	{
		printf("%I64d\n",3*a[n-1]);
	}
	return 0;
}