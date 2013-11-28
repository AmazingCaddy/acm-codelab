#include<iostream>
using namespace std;
int main( )
{
	char ch;
	int a,b,c,t;
	scanf("%d",&t);
	getchar( );
	while( t-- )
	{
		a=b=c=0;
		while( scanf("%c",&ch) && ch!='\n' )
		{
			if( ch>='0' && ch<='9' )
				a++;
			else if( ch>='A' && ch<='Z' || ch>='a' && ch<='z' )
				b++;
			else c++;
		}
		printf("character:%d\nnumber:%d\nothers:%d\n",b,a,c);
	}
	return 0;
}