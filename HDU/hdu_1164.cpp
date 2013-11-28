#include<iostream>
#include<cmath>
#include<stdio.h>
#define MAXN 90000
using namespace std;
bool vis[MAXN];
int p[65000];
int len,cnt;
__int64 ans,a[30],b[30];

void prime( )
{
	__int64 i,j,k;
	len=0;
	memset( vis, false, sizeof( vis ) );
	for( i=2, k=4; i < MAXN; ++i, k+=i+i-1 )
	{
		if( !vis[i] )
		{
			p[len++]=i;
			if( k < MAXN )
			{
				for( j=k; j < MAXN; j+=i )
					vis[j]=true;
			}
		}
	}
}

int num_factor( __int64 n )   //在有素数表的前提下的素因数分解
{
	int i,j=0;
	for( i=0; (__int64)p[i] * p[i] <= n; i++ )
	{
		if( n%p[i]==0 )
		{
			for( b[j]=0; n%p[i]==0; ++b[j], n/=p[i] );
			a[j++]=p[i];
		}
	}
	if( n>1 ) b[j]=1, a[j++]=n;
        return j;
}


int main( int argc, char *argv[] )
{
	int i,n,len;
	prime( );
	while( scanf("%d",&n) != EOF )
	{
		len = num_factor( n );
		printf("%I64d",a[0]);
		b[0]--;
		for( i=0; i<len; i++ )
		{
			while( b[i]-- )
				printf("*%I64d",a[i]);
		}
		printf("\n");
	}
	return 0;
}
