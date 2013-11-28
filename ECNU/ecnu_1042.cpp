#include<stdio.h>
 
int main()
{
	int i,j,n,a[7];
	long int m;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&m);
		a[0]=m/100;
		m=m%100;
		a[1]=m/50;
		m=m%50;
		a[2]=m/20;
		m=m%20;
		a[3]=m/10;
		m=m%10;
		a[4]=m/5;
		m=m%5;
		a[5]=m/2;
		a[6]=m%2;
		printf("%d",a[0]);
		for(j=1;j<7;j++)
			printf(" %d",a[j]);
		printf("\n");
	}
	return 0;
}
