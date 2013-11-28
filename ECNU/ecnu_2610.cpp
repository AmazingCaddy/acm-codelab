#include<iostream>
using namespace std;
int main( )
{
	int t,sum,k,m,s,i;
	scanf("%d",&t);
	while( t-- )
	{
		scanf("%d%d",&m,&k);
		sum=0;
		for( i=0; i<m; i++ )
		{
			scanf("%d",&s);
			if( i<k )sum+=s;
		}
		printf("%d\n",sum);
	}
	return 0;
}