#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<complex>
using namespace std;
typedef complex<double> point;

const int maxn = 50005;
const double eps = 1e-8;

struct line {
	point a, b;
	line( ){ }
	line( point u, point v ) : a( u ), b( v ){ }
};

struct node {
	double yl, yr;
	int id;
}h[ maxn ];

int A[maxn], B[maxn], C[maxn];
double hr[maxn];

int dblcmp( double x ) { return ( x < -eps ? -1 : x > eps ); }
double operator ^( const point & p1, const point & p2 ) { return imag( conj( p1 ) * p2 ); }
double operator &( const point & p1, const point & p2 ) { return real( conj( p1 ) * p2 ); }

point operator * ( const line l0, const line l1 ) {
	double t = l0.a - l1.a ^ l0.b - l1.a;
    double s = l0.b - l1.b ^ l0.a - l1.b;
    return l1.a + ( l1.b - l1.a ) * t / ( t + s );
}

bool cmp( const node & a, const node & b ) {
	if( dblcmp( a.yl - b.yl ) != 0 ) return a.yl < b.yl;
	return a.yr < b.yr ; 
}

bool cmp1( int x, int y ) {
	if( dblcmp( h[x].yr - h[y].yr ) != 0 ) return h[x].yr < h[y].yr;
	return h[x].yl < h[y].yl;
}

int TimeOfSort( int l, int r ) {
	int c = 0;
	if( l < r ) {
		int mid = ( l + r ) >> 1;
		c = TimeOfSort( l, mid ) + TimeOfSort( mid + 1, r );
		int i = l, k = l, j = mid + 1;
		while( i <= mid || j <= r ) {
			if( i <= mid && ( j > r || A[i] <= A[j] ) ) {
				B[k] = A[i];
				++i;
				c += j - mid - 1;
			}
			else {
				B[k] = A[j];
				++j;
			}
			++k;
		}
		for( i = l; i <= r; ++i ) {
			A[i] = B[i];
		}
	}
	return c;
}

int main( ) {
	int n, cnt1, cnt2;
	double l, r, x1, y1, x2, y2;
	//freopen("life.in","r",stdin);
	//freopen("life.out","w",stdout);
	while( scanf("%d", &n) != EOF ) {
		scanf("%lf%lf",&l,&r);
		line Ll = line( point( l, 0 ), point( l, 1000 ) );
		line Lr = line( point( r, 0 ), point( r, 1000 ) );
		cnt1 = cnt2 = 0;
		for( int i = 0; i < n; i++ ) {
			scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
			line L = line( point( x1, y1 ), point( x2, y2 ) );
			if( dblcmp( real( L.a ) - real( L.b ) ) == 0 ) {
				if( dblcmp( real( L.a ) - l ) > 0 && dblcmp( r - real( L.b ) ) > 0 )cnt2++;
			}
			else {
				point p = L * Ll;
				h[cnt1].yl = imag( p );
				p = L * Lr;
				h[cnt1].yr = hr[cnt1] = imag( p );
				//h[cnt1].id = cnt1;
				cnt1++;
			}
		}
		sort( h, h + cnt1, cmp );
		for( int i = 0; i < cnt1; i++ )
			h[i].id = i, A[i] = i;
		sort( A, A + cnt1, cmp1 );
		int ans = TimeOfSort( 0, cnt1 - 1 );
		ans = ans + cnt2 * cnt1;
		printf("%d\n",ans);
	}
	return 0;
}
