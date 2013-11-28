#include <cstdio>
#include <iostream>
#include <cmath>
#include <complex>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
typedef __int64 ll;
priority_queue<ll,vector<ll>,greater<ll> > heap;

int main(int argc, char *argv[])
{
	int x, y, n;
	ll ans;
	scanf("%d",&n);
	for( int i = 0; i < n; i++ )
	{
		scanf("%d",&x);
		heap.push(x);
	}
	ans = 0;
	while( heap.size() != 1 )
	{
		x = heap.top();
		heap.pop();
		y = heap.top();
		heap.pop();
		heap.push( x+y );
		ans += x + y;
	}
	printf("%I64d\n",ans);
	return 0;
}
