#include<stdio.h>
#include<iostream>
#include<cstring>
#include<cstdlib>
#define maxn 200010
using namespace std;
int wa[maxn],wb[maxn],wv[maxn],wu[maxn];
int cmp( int *r, int a, int b, int l )
{ return r[a]==r[b]&&r[a+l]==r[b+l]; }
void da( int *r, int *sa, int n, int m )
{
	int i,j,p,*x=wa,*y=wb,*t;
	for( i=0; i<m; i++ ) wu[i]=0;
	for( i=0; i<n; i++ ) wu[x[i]=r[i]]++;
	for( i=1; i<m; i++ ) wu[i]+=wu[i-1];
	for( i=n-1; i>=0; i-- ) sa[--wu[x[i]]]=i;
	for( j=1,p=1; p<n; j*=2, m=p )
	{
		for( p=0, i=n-j; i<n; i++ ) y[p++]=i;//长度溢出部分
		for( i=0; i<n; i++ ) if( sa[i]>=j ) y[p++]=sa[i]-j;//起始位置为sa[i]-j
		for( i=0; i<n; i++ ) wv[i]=x[y[i]];
		for( i=0; i<m; i++ ) wu[i]=0;
		for( i=0; i<n; i++ ) wu[wv[i]]++;
		for( i=1; i<m; i++ ) wu[i]+=wu[i-1];
		for( i=n-1; i>=0; i-- ) sa[--wu[wv[i]]]=y[i];
		for( t=x, x=y, y=t, p=1, x[sa[0]]=0, i=1; i<n; i++ )
			x[sa[i]]=cmp( y, sa[i-1], sa[i], j ) ? p-1 : p++;
	}
	return;
}
int rank[maxn],height[maxn]; //rank[1..n], height[1..n]
void calheight( int *r, int *sa, int n )
{
	int i,j,k=0;
	for( i=1; i<=n; i++ ) rank[sa[i]]=i;
	for( i=0; i<n; height[rank[i++]]=k )
		for( k ? k-- : 0, j=sa[rank[i]-1]; r[i+k]==r[j+k]; k++ );
	return;
}
int sa[maxn],r[maxn];//sa[0..n-1], sa[i]记录排名为i+1的后缀数组在原数组中的下标
char s[maxn];
int main( int argc, char *argv[] )
{
	int n,i,j,ans;
	while( scanf("%s",s) != EOF )
	{
		j=(int)strlen(s);
		s[j]=1;
		scanf("%s",s+j+1);
		n=(int)strlen(s);
		s[n]=0;
		for( i=0; i<=n; i++ )
			r[i]=s[i];
		da( r, sa, n+1, 127 );
		calheight( r, sa, n );
		ans = 0;
		for( i=2; i<=n; i++ )
			if( height[i]>ans )
			if( j<sa[i-1] && j>sa[i] || j>sa[i-1] && j<sa[i] )
			ans=height[i];
		printf("%d\n",ans);
	}
	return 0;
}
