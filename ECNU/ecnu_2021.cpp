#include<stdio.h>
#include<stdlib.h>
int compare(const void *a,const void *b)
{
	return *(int*)a-*(int*)b;
}

int bisearch(int *a,int m,int n,int x)
{
	int l;
	while(m<=n)
	{
		l=(n+m)/2;
		if(a[l]>x)n=l-1;
		else if(a[l]<x)m=l+1;
		else break;
	}
	return l;
}

int main()
{
	int n,s,i,l,sum;
	int a[20000];
	scanf("%d%d",&n,&s);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

	qsort(a,n,sizeof(int),compare);

	sum=0;
	for(i=0;i<n&&a[i]<=s/2;i++)
	{
		l=bisearch(a,i,n-1,s-a[i]);
		while(a[l]+a[i]<=s&&l<n-1)l++;
		while(a[l]+a[i]>s&&l>0)l--;	//两个while先后顺序不能调换
		sum+=l-i;
	}

	printf("%d\n",sum);
	return 0;
}