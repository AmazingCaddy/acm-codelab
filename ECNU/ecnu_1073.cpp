#include<stdio.h>
#include<string.h>
int main()
{
	int n;
	char a[1024]={0};
	while(scanf("%s",a)!=EOF)
	{
		n=strlen(a);
		printf("%d\n",n);
		memset(a,0,sizeof(a));
	}
	return 0;
}
