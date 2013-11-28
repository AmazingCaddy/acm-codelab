/*
    author: AmazingCaddy
    time:	2011-07-15 12:19:06
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

struct point {
    ll x, y, z;
    point( ) { }
    point(ll _x, ll _y, ll _z) : x(_x), y(_y), z(_z) { }
    void input() { scanf("%lld%lld%lld", &x, &y, &z); }
};

struct node {
    ll fenzi, fenmu;
    node() { }
    node(ll _a, ll _b) : fenzi(_a), fenmu(_b) {
        if (fenzi == 0) fenmu = 1;
        else {
            ll tmp = gcd(fenzi, fenmu);
            fenzi /= tmp;
            fenmu /= tmp;
        }
    }
};

bool operator<(const node &a, const node &b) {
	return a.fenzi * b.fenmu < a.fenmu * b.fenzi;
}

bool operator ==(const point &a, const point &b) {
    return ( a.x == b.x && a.y == b.y && a.z == b.z);
}

point operator ^ (const point &a, const point &b) {
    return point(a.y * b.z - a.z * b.y, -(a.x * b.z - a.z * b.x), a.x * b.y - a.y * b.x);
}

ll operator &(const point &a, const point &b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

point operator +(const point &a, const point &b) {
    return point(a.x + b.x, a.y + b.y, a.z + b.z);
}

point operator -(const point &a, const point &b) {
    return point(a.x - b.x, a.y - b.y, a.z - b.z);
}

// 向量长度的平方
ll distance(const point &p) {
    return ( p.x * p.x + p.y * p.y + p.z * p.z);
}

// 点到线段的距离
node dis(const point &p, const point &a, const point &b) {
    if ((p - a & b - a) >= 0 && (p - b & a - b) >= 0) {
    	ll fenzi = distance((a - p) ^ (b - p));
    	ll fenmu = distance(a - b);
     	return node(fenzi, fenmu);
 	}
    return node( min( distance(a - p), distance(b - p) ), 1 );
}

node lineToline( const point &a, const point &b, const point &c, const point &d )
{
	return min( min( dis( a, c, d ), dis( b, c, d ) ), min( dis( c, a, b ), dis( d, a, b ) ) );
}

// 判断两异面线段的共垂线段是否存在
int nearLL(const point &p1, const point &p2, const point &p3, const point &p4) {
	ll d1 = p1 - p3 & p4 - p3; 	//1343
	ll d2 = p4 - p3 & p2 - p1; 	//4321
	ll d3 = p1 - p3 & p2 - p1;	//1321
	ll d4 = p4 - p3 & p4 - p3; 	//4343
	ll d5 = p2 - p1 & p2 - p1; 	//2121
	ll a = d1 * d2 - d3 * d4, b = d5 * d4 - d2 * d2;
	ll c = d1 * d5 - d2 * d3, d = b;
	if (b < 0) {
		if (a >= b && a <= 0 && c >= d && c <= 0)
		    return 1;
	} else if (b > 0) {
		if (a <= b && a >= 0 && c <= d && c >= 0)
		    return 1;
	}
    return 0;
}

node dis_line( const point& u1,const point& u2, const point& v1, const point& v2){
	point n = (u1 - u2) ^ (v1 - v2);
	ll tmp = (u1 - v1) & n;
	return node( tmp * tmp, distance( n ) );
}

void solve(point p[ ]) {
	node ans;
	if (nearLL(p[ 0 ], p[ 1 ], p[ 2 ], p[ 3 ])) {
		ans = dis_line( p[ 0 ], p[ 1 ], p[ 2 ], p[ 3 ] );
	} else {
		ans = lineToline( p[ 0 ], p[ 1 ], p[ 2 ], p[ 3 ] );
	}
	printf( "%lld %lld\n", ans.fenzi, ans.fenmu );
}

int main(int argc, char *argv[]) {
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        point p[ 5 ];
        for (int i = 0; i < 4; i++)
            p[ i ].input();
        solve(p);
    }
    return 0;
}

