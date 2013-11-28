#include<iostream>
#define N 10001
using namespace std;
bool prime[N];
int main()
{
	int c,i,j,n,count;
	int a[N],b[N];
	scanf("%d",&c);
	while( c-- )
	{
		scanf("%d",&n);
		for( i=0; i<n; i++ )
		{
			a[i]=i+1;
			b[i]=n-i;
		}
		memset(prime,true,sizeof(prime));
		prime[0]=prime[1]=false;
		for ( i = 2 ; i<=100 ; i++ )
			for ( j=2 ; i*j<=10000 ; j++ )
				prime[i*j]=false;
		count=0;
		for( i=0; i<n; i++ )
			if( prime[a[i]] && prime[b[i]] )
				count++;

		printf("%d\n",count);
	}
	return 0;
}
