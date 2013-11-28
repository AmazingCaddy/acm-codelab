#include<iostream>
#include<cmath>
using namespace std;
typedef __int64 LL;
const LL p = 10007;
LL x,y;
int n;

void matrix_mul( LL a[][4], LL b[][4] )
{
	int i,j,k;
	LL c[4][4];
	memset( c, 0, sizeof( c ) );
	for( i=0; i<4; i++ )
		for( j=0; j<4; j++ )
			for( k=0; k<4; k++ )
				c[i][j]+=a[i][k]*b[k][j];
	for( i=0; i<4; i++ )
		for( j=0; j<4; j++ )
			a[i][j]=c[i][j]%p;
}

LL Sn( )
{
	int i;
	LL I[4][4],a[4][4]; 
	memset( I, 0, sizeof( I ) );
	for( i=0; i<4; i++ )
		I[i][i]=1;
	a[0][0]=0,a[0][1]=0,a[0][2]=(y*y)%p,a[0][3]=0;
	a[1][0]=0,a[1][1]=y%p,a[1][2]=((x*2)%p*y)%p,a[1][3]=0;
	a[2][0]=1,a[2][1]=x%p,a[2][2]=(x*x)%p,a[2][3]=1;
	a[3][0]=0,a[3][1]=0,a[3][2]=0,a[3][3]=1;
	while( n )
	{
		if( n & 1 ) matrix_mul( I, a );
		matrix_mul( a, a );
		n>>=1;
	}
	return (I[0][3]+I[1][3]+I[2][3]+I[3][3])%p;
}

int main( )
{
	while( scanf("%d%I64d%I64d",&n,&x,&y) != EOF )
	{
		printf("%I64d\n",Sn( ));
	}
	return 0;
}