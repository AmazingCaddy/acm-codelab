#include<iostream>
using namespace std;
int num[]={1,1,2,6,24,120,720,5040,40320,362880};
bool p[1000001];
int main( )
{
	int i,j,sum,n;
	memset( p, false, sizeof(p) );
	for( i=0; i<(1<<10); i++ )
	{
		sum=0;
		for( j=0; j<10; j++ )
			if( i&(1<<j) )
				sum+=num[j];
		p[sum]=true;
	}
	p[0]=false;
	while( scanf("%d",&n) && n>=0 )
	{
		if( p[n] )printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}