#include<stdio.h>
int main()
{
	int t,n,m;
	int count0,count1;
	scanf("%d",&t);
	while( t-- )
	{
		scanf("%d",&n);
		count1=0;count0=0;
		while( n )
		{
			if( (n & 1) ==1 )count1++;
			if( (n & 1) ==0 )count0++;
			n>>=1;
		}
		printf("%d %d\n",count0,count1);
	}
	return 0;
}