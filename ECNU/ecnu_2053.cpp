#include<stdio.h>
int f(int a,int b)
{
	int max,min;
	if(a>b){max=a;min=b;}
	else {max=b;min=a;}
	if(min==1)return max;
	else return f(max-min,min)+min;
}
 
int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		printf("%d\n",f(n,m));
	}
	return 0;
}