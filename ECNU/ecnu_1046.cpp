//#include<iostream>
//#include<algorithm>
//#define MAXN 4005
//#define M 16000005
//using namespace std;
//int a[M];
//int mat[MAXN][4];
//int bin_search( double k, int l, int r )
//{
//	int mid,low=l,high=r;
//	while( low<=high )
//	{
//		mid=(low+high)>>1;
//		if( a[mid]<k )low=mid+1;
//		else high=mid-1;
//	}
//	return low;
//}
//
//int main( )
//{
//	int n,i,j,k,count;
//	while( scanf("%d",&n) != EOF )
//	{
//		for( i=0; i<n; i++ )
//			scanf("%d%d%d%d",&mat[i][0],&mat[i][1],&mat[i][2],&mat[i][3]);
//		k=0;
//		for( i=0; i<n; i++ )
//			for( j=0; j<n; j++ )
//				a[k++]=mat[i][0]+mat[j][1];
//		sort( a, a+k );
//		count=0;
//		for( i=0; i<n; i++ )
//			for( j=0; j<n; j++ )
//			{
//				int c=bin_search( -(mat[i][2]+mat[j][3])+0.5, 0, k-1 );
//				int d=bin_search( -(mat[i][2]+mat[j][3])-0.5, 0, k-1 );
//				count+=(c-d);
//			}
//		printf("%d\n",count);
//	}
//	return 0;
//}


#include<stdio.h>
#include<string.h>
int p=7999991;
int a[4001],b[4001],c[4001],d[4001];
int h[8000000]={0},f[8000000]={0};
void hash( int a )
{
	int key=(a%p+p)%p;
	while( h[key]!=a && f[key]>0 )key=(key+1)%p;
	h[key]=a;
	f[key]++;
}
long find( int a )
{
	int key=(a%p+p)%p;
	while( h[key]!=a && f[key]>0 )
		key=(key+1)%p;
	return f[key];
}
int main( )
{
	long i,j,t,n;
	scanf("%d",&n);
	for( i=0; i<n; i++ )
		scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
	for( i=0; i<n; i++ )
		for( j=0; j<n; j++ )
			hash(a[i]+b[j]);
	t=0;
	for( i=0; i<n; i++ )
		for( j=0; j<n; j++ )
			t+=find(-c[i]-d[j]);
	printf("%d\n",t);
}