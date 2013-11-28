#include<stdio.h>
#include<stdlib.h>
int compare(const void *a,const void *b)
{
	return *(int*)a-*(int*)b;
}

int main()
{
	int n,k,i,j,t,count,temp;
	int a[2005];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		qsort(a,n,sizeof(int),compare);
		for(i=0;i<n;i++)
			if(a[i]>k/2)break;

		temp=i;
		if(i==n)printf("%d\n",(n+1)/2);
		else 
		{
			count=0;i=0;
			for(j=n-1;j>=temp;)
			{
				if((a[i]+a[j])<=k&&i<temp)
				{
					count++;
					j=j-1;
					i=i+1;
				}
				else
				{
					count++;
					j=j-1;
				}
			}
			count=count+(temp-i+1)/2;
			printf("%d\n",count);
		}
	}
	return 0;
}