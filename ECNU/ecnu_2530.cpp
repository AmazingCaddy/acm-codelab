#include<stdio.h>
int main()
{
	int n,t,i,flag,k,j;
	int a[1005];
	scanf("%d",&t);
	while(t--)
	{
		flag=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(i=0;i<n&&flag!=1;i++)
			for(j=i+1;j<n&&flag!=1;j++)
				for(k=j+1;k<n;k++)
					if(a[i]+a[j]+a[k]==0)
						flag=1;

		if(flag==1)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}