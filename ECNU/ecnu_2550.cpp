#include<stdio.h>
#define N 100
int f(int n)
{
	int i,b;
	if(n==1)return 1;
	else 
	{
		b=1;
		for(i=1;i<=n;i++)
			b*=i;
		return b;
	}
}
int main()
{
	int a[N][N];
	int k,t,n,i,j,sum;
	scanf("%d",&t);
	for(k=0;k<t;k++)
	{
		scanf("%d",&n);
		sum=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				scanf("%d",&a[i][j]);
				sum+=a[i][j];
			}
		}
		printf("Case #%d: %d\n",k+1,sum*f(n-1));
	}
	return 0;
}

			

