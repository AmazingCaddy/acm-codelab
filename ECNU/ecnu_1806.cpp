#include<stdio.h>
int main()
{
	int i,j,n,temp,min;
	int a[1024];
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
			if(a[j]<a[min])
				min=j;
		if(min!=i)
		{
			temp=a[min];
			a[min]=a[i];
			a[i]=temp;
		}
	}
	printf("%d",a[0]);
	for(i=1;i<n;i++)
		printf(" %d",a[i]);
	printf("\n");
	return 0;
}
