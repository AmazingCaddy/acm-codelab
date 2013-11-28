#include<stdio.h>
#define N 100
#define MXA 1000000
int main()
{
	int n,t,i,j,sum;
	int a[N];
	scanf("%d",&t);
	a[0]=1;
	for(i=1;a[i-1]<MXA;i++)
	{
		sum=0;
		for(j=0;j<i;j++)
			sum+=a[j];
		a[i]=2*sum+1;
	}
	while ( t-- )
	{
		scanf("%d",&n);
		for( i=0; ; i++ )
		{
			if(n>=a[i-1]&&n<a[i])break;
		}
		if(n<=(a[i]-1)/2)printf("%d\n",i);
		else printf("%d\n",i+1);
	}
	return 0;
}
