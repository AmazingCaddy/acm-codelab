// �������е�Ҫ��ȼ��ڣ�����һ��ֱ��l�����е��߶ζ��ཻ��

// ֤����������һ��ֱ��l�������߶��ཻ����һ��ֱ��m��l��ֱ����m��������Ҫ���
// ֱ�������߶�ͶӰ��һ�������㼴Ϊ���㡣��l��ÿ���߶εĽ�����lͶӰ��m�ϵĴ���
// ������������������m�������߶���m�ϵ�ͶӰ�й����㣬�����㴹ֱ��m��ֱ��l��
// lһ���������߶��ཻ��

// Ȼ��֤����l�������߶��ཻ�ȼ��ڴ���l��ĳ�����߶εĸ�һ���˵��Һ������߶��ཻ��
// �������Ȼ��
// ��Ҫ�ԣ�����l�������߶��ཻ����ɱ���l�������߶��ཻ������ƽ��l����ĳһ�߶�
// ���ڶ˵�ֹͣ�����Ʋ����ˡ�����Ȼ�������������ת��Ҳ��ת����ת�����ˡ�������һ
// �߶ν�����һ���˵㣩Ϊֹ���������ҵ���һ���µ�l��

// ���Ǳ���ɹ��Ϊö�������߶εĸ�һ���˵㣬��һ��ֱ�ߣ�
// ���ж�ʣ�µ��߶��Ƿ񶼺�����ֱ���н��㡣

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
// �ж��߶�l1�Ƿ���ֱ��l2�ཻ
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
