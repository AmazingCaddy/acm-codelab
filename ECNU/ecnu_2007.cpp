#include<stdio.h>
int main()
{
	__int64 n;
	__int64 catalan[40];
	catalan[0]=0;
	catalan[1]=1;
	for(n=2;n<=35;n++)
		catalan[n]=catalan[n-1]*(2*n-1)*2/(n+1);
	while(scanf("%I64d",&n)!=EOF)
	{
		if(n<34)printf("%I64d\n",catalan[n]);
		if(n==34)
			printf("812944042149730764\n");
		if(n==35)printf("3116285494907301262\n");
	}
	return 0;
}
