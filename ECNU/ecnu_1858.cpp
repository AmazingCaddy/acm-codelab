#include<iostream>
using namespace std;
void print( int n )
{
	int t;
	if( n==0 )return ;
	print( n/4 );
	t=n%4;
	if( t==2 )printf("4");
	else if( t==3 )printf("9");
	else printf("%d",t);
}

int main( )
{
	int n;
	while( scanf("%d",&n) != EOF )
	{
		if( n==0 )printf("0");
		else print( n );
		printf("\n");
	}
	return 0;
}