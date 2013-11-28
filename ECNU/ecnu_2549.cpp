#include<stdio.h>
#include<stdlib.h>
#define N 30000

int compare(const void *a,const void *b)
{
	return *(int*)b-*(int*)a;
}

float f(int* a,int *b,int n,int flag,float avg)
{
	int i=0,j=0,temp;
	float avg1,sum;
	for(i=0;i<n;i++)
	{
		if(flag%2==0&&a[i]>=avg)b[j++]=a[i];
		if(flag%2==1&&a[i]<=avg)b[j++]=a[i];
	}
	
	for(i=0;i<j/2;i++)
	{
		temp=b[i];
		b[i]=b[j-1-i];
		b[j-1-i]=temp;
	}
	sum=0;
	for(i=0;i<j;i++)
		sum+=b[i];
	avg1=sum/j;
	if(avg==avg1)return avg1;
	else return f(b,a,j,flag+1,avg1);
}

int main()
{
	int t,n,i,j,flag=0;
	float avg,sum;
	int num[N],temp[N];
	scanf("%d",&t);
	for(j=0;j<t;j++)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&num[i]);
		sum=0;
		for(i=0;i<n;i++)
			sum+=num[i];
		avg=sum/n;

		qsort(num,n,sizeof(int),compare);

		printf("Case #%d: %.3f\n",j+1,f(num,temp,n,flag,avg));
	}
	return 0;
}