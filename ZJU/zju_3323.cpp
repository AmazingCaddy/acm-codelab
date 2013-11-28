#include<iostream>
#include<string.h>
using namespace std;
int main( )
{
	char str[30];
	char a[30];
	int i,j,t,len;
	scanf("%d",&t);
	while( t-- )
	{
		scanf("%s",str);
		len = strlen( str );
		j=0;
		for( i=0; i<len; i++  )
		{
			if( str[i]>='0' && str[i]<='9' )
				continue;
			a[j++]=str[i];
		}
		a[j]=0;
		printf("%s\n",a);
	}
	return 0;
}