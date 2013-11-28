#include<stdio.h>
#define N 1000
#define max(a,b) a>=b?a:b
int main()
{
	int t,n,i,sum,max;
	int a[N];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for( i=0; i<n; i++ )
			scanf("%d",&a[i]);
		sum=a[0];max=a[0];
		for( i=1; i<n; i++ )
		{
			if(sum<0)sum=a[i]; 
			else sum+=a[i];
			max=max(max,sum);
		}
		if(max<0)printf("0\n");
		else printf("%d\n",max);
	}
	return 0;
}