#include<stdio.h>	
int a[1000][1000],b[1000][1000];
int main()
{
	int d,i,j,n,m;
	scanf("%d",&d);
	while(d--)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				scanf("%d",&a[i][j]);
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				scanf("%d",&b[i][j]);
				a[i][j]+=b[i][j];
			}
		}
		for(i=0;i<n;i++)
		{
			printf("%d",a[i][0]);
			for(j=1;j<m;j++)
				printf(" %d",a[i][j]);
			printf("\n");
		}
	}
	return 0;
}