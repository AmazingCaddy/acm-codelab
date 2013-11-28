#include<iostream>
#include<cmath>
using namespace std;
int a[65];
int p[]={9,8,7,6,5,4,3,2};
int main( )
{
	int i,j,n;
	while( scanf("%d",&n) != EOF )
	{
		if( n==0 )printf("%d\n",10);
		else if( n==1 )printf("1\n");
		else
		{
			j=0;
			for( i=0; i<8 && n!=1; i++ ) 
			{
				if( n%p[i]==0 )
				{
					while( !(n%p[i]) )
						a[j++]=p[i],n/=p[i];
				}
			}
			if( n>10 )printf("-1\n");
			else 
			{
				for( i=j-1; i>=0; i-- )
					printf("%d",a[i]);
				printf("\n");
			}

		}
	}
	return 0;
}