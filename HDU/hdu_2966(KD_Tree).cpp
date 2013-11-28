#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
typedef __int64 ll;
const ll inf = 4611686018427387904LL;
const int maxn = 100050;

struct point
{
	int x, y;
}p[maxn], pp[maxn];

bool cmp1( const point & a, const point & b ) { return a.x < b.x; }
bool cmp2( const point & a, const point & b ) { return a.y < b.y; }

struct node
{
	int axis;
	point mid;
	node *ch[2];   // 0 left, 1 right
}tree[maxn];
int len;
ll ans;

node * NewNode( )
{
	tree[len].ch[0] = tree[len].ch[1] = NULL;
	return & tree[len++];
}

node * make_tree( int l, int r, int dep )
{
	if( l > r ) return NULL;
	node * q = NewNode( );
	int t = dep % 2;
	q -> axis = t;
	if( l == r ) { q -> mid = p[l]; return q; }

	if( t == 0 ) sort( p + l, p + r + 1, cmp1 ); // X - axis
	else sort( p + l, p + r + 1, cmp2 );         // Y - axis
	
	int mid = ( l + r ) >> 1;
	q -> mid = p[mid];
	
	q -> ch[0] = make_tree( l, mid - 1, dep + 1 );
	q -> ch[1] = make_tree( mid + 1, r, dep + 1 );
	return q;
}

ll dis( point a, point b )
{
	ll x = a.x - b.x;
	ll y = a.y - b.y;
	return x * x + y * y;
}

void search_nearpoint( node * q, const point & a )
{
	// 首先找到叶结点
	if( q == NULL ) return;
	
	int tmp, s;
	if( q -> axis == 0 ) tmp = q -> mid.x, s = a.x; // X - axis
	else tmp = q -> mid.y, s = a.y;                 // Y - axis
	
	if( s <= tmp ) search_nearpoint( q -> ch[0], a ); // leftson
	else search_nearpoint( q -> ch[1], a );           // rightson

	ll d = dis( q -> mid, a );
	if( d && d < ans ) ans = d;

	if( (ll)( tmp - s ) * ( tmp - s ) < ans )  // 查找另一半平面
	{
		if( s <= tmp )search_nearpoint( q -> ch[1], a ); 
		else search_nearpoint( q -> ch[0], a );
	}
}

int main(int argc, char *argv[])
{
	node * root;
	int cas, n, x, y;
	scanf("%d",&cas);
	while( cas-- )
	{
		scanf("%d",&n);
		for( int i = 0; i < n; i++ )
		{
			scanf("%d%d",&p[i].x,&p[i].y);
			pp[i] = p[i];
		}
		len = 0;
		root = make_tree( 0, n - 1, 0 );
		for( int i = 0; i < n; i++ )
		{
			ans = inf;
			search_nearpoint( root, pp[i] );
			printf("%I64d\n",ans);
		}
	}
	return 0;
}
