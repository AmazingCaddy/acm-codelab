#include<iostream>
using namespace std;

void print( int h )
{
	int i;
	if( h%2==0 )
	{
		for( i=0; i<h/2; i++ )
			printf("8");
		printf("\n");
	}
	else 
	{
		printf("4");
		for( i=0; i<h/2; i++ )
			printf("8");
		printf("\n");
	}
}

int main()
{
	int h;
	while( scanf("%d",&h) != EOF )
	{
		if( h==0 )printf("1\n");
		if( h==1 )printf("0\n");
		if( h>=2 )print( h );
	}
	return 0;
}