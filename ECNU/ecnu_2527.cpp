#include<stdio.h>	
int main()
{
	int n,p,m,t,cas;
	int i,j;
	int a[100][100];
	scanf("%d",&cas);
	while(cas--)
	{
		scanf("%d%d%d%d",&n,&p,&m,&t);
		for(i=0;i<100;i++)
			a[0][i]=0;
		a[0][p-1]=1;
		for(i=1;i<=m;i++)
		{
			for(j=0;j<n;j++)
			{
				if(j==0)a[i][j]=a[i-1][j+1];
				else if(j==n-1)a[i][j]=a[i-1][j-1];
				else a[i][j]=a[i-1][j-1]+a[i-1][j+1];
			}
		}
		printf("%d\n",a[m][t-1]);
	}
	return 0;
}

