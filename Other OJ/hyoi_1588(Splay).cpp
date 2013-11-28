#include <cstdio>
#include <iostream>
using namespace std;

//#define keyTree ( ch[ ch[root][1] ][0] )
const int maxn = 222222;
typedef long long LL;
struct SplayTree{
	int ch[maxn][2];
	int pre[maxn];
	int root, top1, top2;
	int ss[maxn], que[maxn];
	LL val[maxn];

	void Rotate( int x, int f ){
		int y = pre[x];
		ch[y][!f] = ch[x][f];
		if( ch[x][f] ) pre[ ch[x][f] ] = y;
		pre[x] = pre[y];
		if( pre[y] ) ch[ pre[y] ][ ch[pre[y]][1] == y ] = x;
		ch[x][f] = y;
		pre[y] = x;
	}

	void Splay( int x, int goal ){
		while( pre[x] != goal ){
			if( pre[ pre[x] ] == goal ) Rotate( x, ch[ pre[x] ][0] == x );
			else {
				int y = pre[x], z = pre[y];
				int f = ( ch[z][0] == y );
				if( ch[y][f] == x ) Rotate( x, !f ), Rotate( x, f );
				else Rotate( y, f ), Rotate( x, f );
			}
		}
		if( goal == 0 ) root = x;
	}
	int find( LL k, int &y ){
		int x = root;
		while( x ){
			y = x;
			if( k < val[x] ) x = ch[x][0];
			else if( k > val[x] ) x = ch[x][1];
			else return y; // 已经存在
		}
		return -1; // 
	}

	int insert( LL k ){
		int x, y;
		if( root == 0 ){
			NewNode( x );
			val[x] = k,	root = x;
			return 1;
		}
		if( find( k, y ) != -1 ) { Splay( y, 0 ); return 0; }
		NewNode( x );
		val[x] = k, pre[x] = y;
		if( val[y] > k ) ch[y][0] = x;
		else ch[y][1] = x;
		Splay( x, 0 );
		return 1;
	}

	LL findmax( int v ){
		while( ch[v][1] ) v = ch[v][1];
		return  val[v]  ;
	}

	LL findmin( int v ){
		while( ch[v][0] ) v = ch[v][0];
		return  val[v]  ;
	}

	int pred_succ( LL k, LL & t1, LL & t2 ){
		int y;
		if( !insert( k ) ) return 0;
		t1 = t2 = -1 ;
		if( ch[root][0] )t1 = findmax( ch[root][0] );
		if( ch[root][1] )t2 = findmin( ch[root][1] );
		return 1;
	}
	//以下是题目的特定函数:
	void NewNode( int &x ){
		if( top2 ) x = ss[--top2];//用栈手动压的内存池
		else x = ++top1;
		ch[x][0] = ch[x][1] = pre[x] = 0;
	}
	/*这是题目特定函数*/
	void init( ){
		ch[0][0] = ch[0][1] = pre[0] =  0;
		root = top1 = top2 = 0;
	}

}spt;

LL min( LL a, LL b ) { return ( a < b ? a : b ); }
LL ABS( LL x ){ return ( x < 0 ? -x : x ); }

int main( ) 
{
	int n; LL tmp, ans;
	while( scanf("%d",&n) != EOF ){
		if( n == 0 ){ printf("0\n"); continue; }
		spt.init( );
		scanf("%I64d",&tmp);
		ans = tmp;
		spt.insert( tmp );
		for( int i = 1; i < n; i++ ){
			if( scanf("%I64d",&tmp) == EOF ) tmp = 0 ;
			LL t1, t2;
			if( spt.pred_succ( tmp, t1, t2 ) == 0 ) continue;
			if( t1 == -1 && t2 != -1 ) ans += ABS( t2 - tmp );
			else if( t2 == -1 && t1 != -1 ) ans += ABS( t1 - tmp );
			else if( t1 != -1 && t2 != -1 )ans += min( ABS( t1 - tmp ), ABS( t2 - tmp ) );
			//cout << t1 << "  " << t2 << " " << ans << endl;
		}
		printf("%I64d\n",ans);
		//break;
	}
	return 0;
}
