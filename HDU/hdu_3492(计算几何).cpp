// 首先题中的要求等价于：存在一条直线l和所有的线段都相交。

// 证明：若存在一条直线l和所有线段相交，作一条直线m和l垂直，则m就是题中要求的
// 直线所有线段投影的一个公共点即为垂足。（l和每条线段的交点沿l投影到m上的垂足
// 处）反过来，若存在m，所有线段在m上的投影有公共点，则过这点垂直于m作直线l，
// l一定和所有线段相交。

// 然后证存在l和所有线段相交等价于存在l过某两条线段的各一个端点且和所有线段相交。
// 充分性显然。
// 必要性：若有l和所有线段相交，则可保持l和所有线段相交，左右平移l到和某一线段
// 交于端点停止（“移不动了”）。然后绕这个交点旋转。也是转到“转不动了”（和另一
// 线段交于其一个端点）为止。这样就找到了一个新的l。

// 于是本题可归结为枚举两两线段的各一个端点，连一条直线，
// 再判断剩下的线段是否都和这条直线有交点。

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<complex>
#include<cmath>
#include<iostream>
using namespace std;

typedef complex<double> point;

const int maxn = 330;
const double eps = 1e-8;
const double pi = acos( -1.0 );
const double inf = 1e20;

struct line
{
	point a, b;
	line( ){ }
	line( point u, point v ) : a( u ), b( v ){ }
};

point p[maxn<<1];
line l[maxn];

double operator ^( const point & p1, const point & p2 ) { return imag(conj(p1)*p2); }
double operator &( const point & p1, const point & p2 ) { return real(conj(p1)*p2); }
int dblcmp( double x ) { return ( x < -eps ? -1 : x > eps ); }

bool same( const point & p1, const point & p2 )
{
	if( dblcmp( real(p1) - real(p2) ) == 0 && dblcmp( imag(p1) - imag(p2) ) == 0 )
		return true;
	return false;
}
// 判断线段l1是否与直线l2相交
bool segcross( line l1, line l2 )
{
	if( dblcmp( l1.a - l2.a ^ l2.b - l2.a ) * 
		dblcmp( l2.b - l2.a ^ l1.b - l2.a ) >= 0 )
		return true;
	return false;
}

bool check( const point & p1, const point & p2, int n )
{
	line l0 = line( p1, p2 );
	for( int k = 0; k < n; k++ )
		if( !segcross( l[k], l0 ) ) return false;
	return true;
}

bool solve( int n )
{
	int len = n << 1;
	int cnt = 0;
	for( int i = 0; i < len; i++ )
	{
		for( int j = i + 1; j < len; j++ )
		{
			if( same( p[i], p[j] ) ) 
			{
				cnt++;
				continue;
			}
			if( check( p[i], p[j], n ) )
				return true;
		}
	}
	if( cnt == len * ( len - 1 ) / 2 ) return true;
	return false;
}

int main( )
{
	int t, n;
	double x1, x2, y1, y2;
	//freopen("1005.in","r",stdin);
	//freopen("out.txt","w",stdout);
	scanf("%d",&t);
	while( t-- )
	{
		scanf("%d",&n);
		int len = 0;
		for( int i = 0; i < n; i++ )
		{
			scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
			p[len++] = point( x1, y1 );
			p[len++] = point( x2, y2 );
			l[i] = line( p[len-2], p[len-1] );
		}
		if( solve( n ) ) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
