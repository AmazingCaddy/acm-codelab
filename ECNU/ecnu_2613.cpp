#include<iostream>
using namespace std;
int main()
{
	int t,n,i,sum;
	scanf("%d",&t);
	while( t-- )
	{
		scanf("%d",&n);
		if( n==1 )printf("1\n");
		else 
		{
			sum=1;
			for( i=1; i<n; i++ )
				sum=(sum*i)%1999;
			printf("%d\n",sum);
		}
	}
	return 0;
}