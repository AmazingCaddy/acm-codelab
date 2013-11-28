#include<iostream>
#include<cmath>
using namespace std;
int main( )
{
	int n,a,b,p;
	scanf("%d",&n);
	while( n-- )
	{
		scanf("%d%d%d",&p,&a,&b);
		if( a>b )
			printf("A\n");
		else printf("B\n");
	}
	return 0;
}
