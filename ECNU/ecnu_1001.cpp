#include <stdio.h>
#include <string.h>
int main()
{
	int n,m,i,max;
	char temp;
	char a[500]={0},b[500]={0},c[500]={0};
	while(scanf("%s",a)!=EOF)
	{
		scanf("%s",b);
		n=strlen(a);m=strlen(b);
		for(i=0;i<n/2;i++)
		{
			temp=a[i]-48;
			a[i]=a[n-i-1]-48;
			a[n-i-1]=temp;
		}
		for(i=0;i<m/2;i++)
		{
			temp=b[i]-48;
			b[i]=b[m-i-1]-48;
			b[m-i-1]=temp;
		}
		if(n%2==1)a[n/2]=a[n/2]-48;
		if(m%2==1)b[m/2]=b[m/2]-48;
		if(n>m)max=n;
		else max=m;
		for(i=0;i<max;i++)
		{
			c[i]=a[i]+b[i]+c[i];
			if(c[i]>9)
			{
				c[i]=c[i]-10;
				c[i+1]=c[i+1]+1;
			}
		}
		if(c[max]==1)
		{
			for(i=max;i>=0;i--)
				printf("%d",c[i]);
			printf("\n");
		}
		else 
		{
			for(i=max-1;i>=0;i--)
				printf("%d",c[i]);
			printf("\n");
		}
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
	}
	return 0;
}