#include<stdio.h>
#define max(m,n) m>=n?m:n
#define min(m,n) m<n?m:n
int gcd( int m, int n )
{
	int temp,x;
	x=max(m,n);
	n=min(m,n);
	m=x;
	while( n )
	{
		temp=m%n;
		m=n;
		n=temp;
	}
	return m;
}

int lcm( int m, int n )
{
	return m*n/gcd(m,n);
}

int main()
{
	int t,a,b;
	scanf("%d",&t);
	while( t-- )
	{
		scanf("%d%d",&a,&b);
		printf("%d %d\n",gcd(a,b),lcm(a,b));
	}
	return 0;
}