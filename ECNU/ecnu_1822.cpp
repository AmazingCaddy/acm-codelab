#include<stdio.h>
int main()
{
	__int64 a[120],b[60];       //a为无序移法，b为有序移法
	int n,i;
	while(scanf("%d",&n)!=EOF)
	{
		a[0]=2;
		for(i=1;i<n;i++)
		{
			a[i]=((a[i-1]/2+1)*2-1)*2;
		}
		b[0]=3;
		for(i=1;i<n;i++)
		{
			b[i]=a[i-1]+2+a[i-1]+2+b[i-1];
		}
		printf("%I64d\n",b[n-1]);
	}

	return 0;
}