#include<iostream>
using namespace std;
int month[]={0,31,28,31,30,31,30,31,31,30,31,30,31};

bool is_right( int n, int m )
{
	if( m<1 )return false;
	else if( m>30 && ( n==4 || n==6 || n==9 || n==11 ) ) return false;
	else if( m>28 && ( n==2 ) ) return false;
	else if( m>31 && ( n==1 || n==3 || n==5 || n==7|| n==8 || n==10 || n==12 ) )
		return false;
	return true;
}

int main( )
{
	int n,m,sum,i;
	while( scanf("%d%d",&n,&m) != EOF )
	{
		if( !is_right( m, n ) )
			printf("Impossible\n");
		else 
		{
			sum=0;
			for( i=1; i<m; i++ )
				sum+=month[i];
			sum+=n;
			printf("%d\n",(sum-1)%7+1);
		}
	}
	return 0;
}