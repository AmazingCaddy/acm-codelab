#include<stdio.h>
#include<string.h>
int main()
{
	int i,n;
	char str[10005];	
	for(;gets(str)!=0;)
	{
		n=strlen(str);
		for(i=n-1;i>=0;i--)
			printf("%c",str[i]);
		printf("\n");
	}
	return 0;
}
