#include<iostream>
#include<cstdio>
#include<string>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 25020;
priority_queue< int, vector<int>, less<int> > heap;

struct node
{
	int T, D;
};
node trap[ maxn ];

bool cmp( const node & a, const node & b )
{
	if( a.D == b.D ) return a.T < b.T;
	return a.D < b.D;
}

int main( )
{
	int n, k, Time, cnt;
	while( scanf("%d%d",&n,&k) != EOF )
	{
		for( int i = 0; i < n; i++ )
			scanf("%d%d",&trap[ i ].T, &trap[ i ].D);
		sort( trap, trap + n, cmp );
		while( !heap.empty( ) )heap.pop( );
		Time = 0, cnt = k;
		int i;
		for( i = 0; i < n; i++ )
		{
			heap.push( trap[ i ].T );
			Time += trap[ i ].T;
			while( Time > trap[ i ].D && !heap.empty( ) )
			{
                Time -= heap.top( );
				heap.pop( );
                cnt--;
            }
			if( cnt < 1 || Time > trap[ i ].D )
				break;
		}
		if( i == n )printf("%d\n",k - cnt);
		else printf("-1\n");
	}
	return 0;
}