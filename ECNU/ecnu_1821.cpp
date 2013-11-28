#include<stdio.h>
int main()
{
	long long a[60],temp;
	int n,i;
	while(scanf("%d",&n)!=EOF)
	{
		temp=1;
	    for(i=0;i<n;i++)
			temp*=2;
		printf("%lld\n",temp*2-2);
	}
	return 0;
}