#include<stdio.h>
int main()
{
	int n,k,i,j,sum,sum1,sum2,min,temp;
	while(scanf("%d%d",&k,&n)!=EOF)
	{
		temp=(k-2+1)*(k-2)/2;
		for(i=k;i>1;i--)
		{
			sum1=0;j=i;
			while(j<k)
			{
				sum1=sum1+(k-j)*n;
				j++;
			}
			sum2=0;j=i;
			while(j>2)
			{
				sum2=sum2+(i-j);
				j--;
			}
			sum=sum1+sum2;
			if(sum<temp)
			{
				temp=sum;
				min=i;
			}
		}
		printf("%d\n",min);
	}
	return 0;
}
		

