#include<stdio.h>
int main()
{
	int n,t,i,j,k,max,maxj,temp;
	int a[1005];
	scanf("%d%d",&n,&t);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	if(n==1)
	{
		for(i=0;i<t;i++)
			printf("1\n");
	}
	else
	{
		for(i=0;i<t;i++)
		{
			max=-1;maxj=0;
			for(j=0;j<n;j++)
			{
				if(a[j]>max)
				{
					max=a[j];
					maxj=j;
				}
			}               //找出最大的数

			printf("%d\n",maxj+1);
			for(j=0;j<n;j++)
				if(j!=maxj)
					a[j]+=a[maxj]/(n-1);
			temp=a[maxj]%(n-1);
			for(k=0;k<n;k++)
			{
				if(temp==0)break;
				if(k!=maxj)
				{
					a[k]++;
					temp--;
				}
			}
			a[maxj]=0;
		}
	}
	return 0;
}