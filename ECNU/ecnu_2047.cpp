//#include<iostream>
//#define MAXN 65540
//using namespace std;
//bool p[MAXN];
//int P[8000];
//double num[MAXN];
//int stack[40];
//void make_prime( )
//{
//	int i,j,cnt;
//	memset( p, true, sizeof(p) );
//	p[0]=p[1]=false;
//	for( i=2; i<=256; i++ )
//		for( j=2; j*i<=65536; j++ )
//			p[i*j]=false;
//	cnt=0;
//	for( i=2; i<=10000; i++ )
//		if( p[i] )
//			P[cnt++]=i;
//}
//
//int function( int n )
//{
//	int i=0,j=0;
//	while( n!=1 )
//	{
//		if( n%P[i]==0 )
//			stack[j++]=P[i],n/=P[i];
//		else i++;
//	}
//	return j;
//}
//
//int main( )
//{
//	int i,j,n,len,a;
//	double x;
//	make_prime( );
//	num[1]=1;
//	for( i=2; i<=10000; i++ )
//	{
//		len=function( i );
//		a=stack[0];
//		x=1-1/(a*1.0);
//		for( j=1; j<len; j++ )
//		{
//			if( stack[j]!=a )
//			{
//				a=stack[j];
//				x=x*(1-1/(a*1.0));
//			}
//		}
//		num[i]=x*i;
//	}
//	while( scanf("%d",&n) != EOF )
//	{
//		printf("%.lf\n",num[n]);
//	}
//	return 0;
//}


int fai( int n )
{
	int m=1;
	for( i=2; i*i<=n; i++ )
	{
		if( n%i==0 )
		{
			m*=i-1;
			n/=i;
			while( n%i==0 )
			{
				m*=i;
				n/=i;
			}
		}
	}
	if( n>1 ) m*=n-1;
	return m;
}