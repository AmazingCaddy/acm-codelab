#include<iostream>
#include<cstdio>
#include<complex>
#include<vector>
#include<deque>
#include<cmath>
#include<algorithm>
#define MAXN 10003
using namespace std;

const double eps = 1e-8;
const double PI  = acos(-1.0);
typedef complex<double> point;

point A[MAXN],B[MAXN];
int main(  )
{
    int n,t,i,k=1;
    point p;
    double x,y,x1,x2,y1,y2,tt;
    scanf("%d",&t);
    while( t-- )
    {
        scanf("%d",&n);
        for( i=0; i<n; i++ )
        {
            scanf("%lf%lf",&x,&y);
            A[i]=point( x, y );
        }
        scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
        B[0]=point( x1, y1 );
        B[1]=point( x2, y2 );
        for( i=1; i<n; i++ )
            A[i]-=A[0];
        tt = real( conj( A[1] ) * A[1] );
        p.real( real( conj( A[1] ) * ( B[1] - B[0] ) ) / tt );
        p.imag( imag( conj( A[1] ) * ( B[1] - B[0] ) ) / tt );
        for( i=2; i<n; i++ )
        {
            B[i] = A[i] * p;
            B[i] += B[0];
        }
        printf("Case %d:\n",k++);
        for( i=0; i<n; i++ )
        {
            if( fabs( B[i].real( ) ) < eps ) B[i].real( 0.0 );
            if( fabs( B[i].imag( ) ) < eps ) B[i].imag( 0.0 );
            printf("%.2lf %.2lf\n",B[i].real( ),B[i].imag( ));
        }
    }
    return 0;
}
