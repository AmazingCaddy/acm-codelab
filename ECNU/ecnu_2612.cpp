#include<iostream>
using namespace std;
int main()
{
	int i,n,t,j;
	char ch;
	scanf("%d%*c",&t);
	while( t-- )
	{
		scanf("%c",&ch);
		scanf("%d%*c",&n);
		if( ch=='P' )
		{
			for( i=0; i<n+2; i++ )
				printf("0");
			printf("\n");
			for( i=0; i<n; i++ )
			{
				printf("0");
				for( j=0; j<n; j++ )
					printf("1");
				printf("0\n");
			}
			for( i=0; i<n+2; i++ )
				printf("0");
			printf("\n");
			for( i=0; i<n+1; i++ )
			{
				printf("0");
				for( j=0; j<n+1; j++ )
					printf("1");
				printf("\n");
			}
		}
		if( ch=='C' )
		{
			for( i=0; i<n+2; i++ )
				printf("0");
			printf("\n");
			for( i=0; i<2*n+1; i++ )
			{
				printf("0");
				for( j=0; j<n+1; j++ )
					printf("1");
				printf("\n");
			}
			for( i=0; i<n+2; i++ )
				printf("0");
			printf("\n");
		}
	}
	return 0;
}