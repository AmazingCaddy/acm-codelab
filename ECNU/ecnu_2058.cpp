#include<iostream>
using namespace std;
int page;
int Time( int s, int t, int r )
{
	int rr,sum=0;
	rr=page/(s*t)*s*t;
	if( page-rr>0 )
	{
		sum=sum+rr/(s*t)*(t+r);
		sum=sum+(page-rr+s-1)/s;
	}
	else if( page==rr )
		sum=rr/(s*t)*(t+r)-r;
	return sum;
}

int main( )
{
	int k,i,s,t,r;
	scanf("%d%d",&page,&k);
	for( i=0; i<k; i++ )
	{
		scanf("%d%d%d",&s,&t,&r);
		printf("%d\n",Time( s, t, r ));
	}
	return 0;
}