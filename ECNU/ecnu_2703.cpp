#include<iostream>
using namespace std;
int main( )
{
	int n,r,c,rest,min,t;
	int i,j,count,s,x;
	while( scanf("%d%d%d",&n,&r,&c) != EOF )
	{
		if( n==1 && r==1 && c==1 )printf("1\n#\n");
		else 
		{
			if( r>c )min=c;
			else min=r;
			if( ( t=(n+1)/2 ) < min )
			{
				printf("%d\n",t);
				for( j=0; j<c; j++ )
				{
					if( j<t )printf("#");
					else printf(".");
				}
				printf("\n");
				for( i=1; i<r; i++ )
				{
					if( i<n/2+1 )printf("#");
					else printf(".");
					for( j=1; j<c; j++ )
						printf(".");
					printf("\n");
				}
			}
			else if( r+c <= n )
			{
				printf("%d\n",min);
				count=n-(r+c-1);
				for( j=0; j<c; j++ )
					printf("#");
				printf("\n");
				x=t=count/(c-1);
				s=count%(c-1);
				for( i=1; i<r; i++ )
				{
					if( i<=t )
					{
						for( j=0; j<c; j++ )
							printf("#");
						printf("\n");
					}
					else if( i == t+1 )
					{
						printf("#");
						for( j=1; j<c; j++ )
						{
							if( j<s+1 )printf("#");
							else printf(".");
						}
						printf("\n");
					}
					else
					{
						printf("#");
						for( j=1; j<c; j++ )
							printf(".");
						printf("\n");
					}
				}
			}
			else 
			{
				if( r==min )
				{
					printf("%d\n",min);
					for( j=0; j<c; j++ )
					{
						if( j<=n-r ) printf("#");
						else printf(".");
					}
					printf("\n");
					for( i=1; i<r; i++ )
					{
						printf("#");
						for( j=1; j<c; j++ )
							printf(".");
						printf("\n");
					}
				}
				if( c==min )
				{
					printf("%d\n",min);
					for( j=0; j<c; j++ )
						printf("#");
					printf("\n");
					for( i=1; i<r; i++ )
					{
						if( i<=n-c )printf("#");
						else printf(".");
						for( j=1; j<c; j++ )
							printf(".");
						printf("\n");
					}
				}
			}
		}
	}
	return 0;
}