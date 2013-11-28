#include<stdio.h>
int main()
{
	int i,n,sum,sum1,sum2,sum3,sum4;
	while(scanf("%d",&n)&&n!=0)
	{
		sum1=1;sum2=0;sum3=0;sum4=0;
		for(i=1;i<n;i++)
		{
			sum4=sum4+sum3;
			sum3=sum2;
			sum2=sum1;
			sum1=sum4;
		}
		sum=sum1+sum2+sum3+sum4;
		printf("%d\n",sum);
	}
	return 0;
}
