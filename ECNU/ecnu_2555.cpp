#include<iostream>
#define MAXN 2005
using namespace std;
int a[MAXN],b[MAXN],c[MAXN],d[MAXN];

int search1( int len, int k )
{
	int low=1,high=len,mid;
	while( low<=high )
	{
		mid=(low+high)/2;
		//if( k>d[mid] ) low=mid+1;
        //else if( k<d[mid] ) high=mid-1;
        //else return mid;
		if( k>=d[mid] ) low=mid+1;
        else high=mid-1;
	}
	return low;
}

int search2( int len, int k )
{
	int low=1,high=len,mid;
	while( low<=high )
	{
		mid=(low+high)/2;
		if( k<d[mid] ) low=mid+1;
        else if( k>d[mid] ) high=mid-1;
        else return mid;
	}
	return low;
}

void increase( int n )
{
	int i,len,t;
	for( i=0; i<n; i++ )
		b[i]=1;
	len=1;
	d[len]=a[0];
	for( i=1; i<n; i++ )
	{
		if( a[i]>d[len] )
			d[++len]=a[i],b[i]=len;
		else 
		{
			t=search1( len, a[i] );
			d[t]=a[i];
			b[i]=t;
		}
	}
}

void decrease( int n )
{
	int i,len,t;
	for( i=0; i<n; i++ )
		c[i]=1;
	len=1;
	d[len]=a[0];
	for( i=1; i<n; i++ )
	{
		if( a[i]<d[len] )
			d[++len]=a[i],c[i]=len;
		else 
		{
			t=search2( len, a[i] );
			d[t]=a[i];
			c[i]=t;
		}
	}
}

int main( )
{
	int i,n,max;
	while( scanf("%d",&n) !=EOF )
	{
		for( i=0; i<n; i++ )
			scanf("%d",&a[i]);
		decrease( n );
		increase( n );
		max=0;
		for( i=0; i<n; i++ )
			if( b[i]+c[i]-1>max )max=b[i]+c[i]-1;
		printf("%d\n",max);
	}
	return 0;
}