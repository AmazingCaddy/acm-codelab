#include <stdio.h>

#define N 510

char str[ N ];

int R[ N ];
int L[ N ];

int n, m;

int cal ( int a, int b ) {
	int head = a, tail = a - 1;
	int step, sl, sr;
	
	step = 1;
	L[ 0 ] = 0;
	while ( true ) {
		while ( tail >= 0 && str[ tail ] == '1' ) {
			--tail;
		}
		if ( tail < 0 ) break;
		L[ step ] = head - tail + L[ step - 1 ];
		--head, --tail, ++step;
	}
	sl = step;
	
	head = b, tail = b + 1;
	step = 1;
	R[ 0 ] = 0;
	while ( true ) {
		while ( tail < n && str[ tail ] == '1' ) {
			++tail;
		}
		if ( tail >= n ) break;
		R[ step ] = tail - head + R[ step - 1 ];
		++head, ++tail, ++step;
	}
	sr = step;
	
	int ret = 0;
	for ( int i = 0 ; i < sl ; ++i ) {
		int cost = m - L[ i ];
		if ( cost < 0 ) break;
		
		int l = 0, r = sr, mid = ( l + r ) / 2;
		
		while ( mid != l ) {
			if ( R[ mid ] > cost ) r = mid;
			else l = mid;
			mid = ( l + r ) / 2;
		}
		if ( ret < i + mid + b - a - 1 )
			ret = i + mid + b - a - 1;
	}
	return ret;
}

int main ( void ) {
//	freopen ( "in", "r", stdin );
	int cas;
	scanf ( "%d", &cas );
	for ( int t = 1 ; t <= cas ; ++t ) {
		scanf ( "%d%d", &n, &m );
		scanf ( "%s", str + 1 );
		str[ 0 ] = str[ n + 1 ] = '1';
		n += 2;
		
		int pre = -1, ans = 0;
		for ( int i = 0 ; i < n ; ++i ) {
			if ( str[ i ] == '1' ) {
				if ( pre != -1 ) {
					int tmp = cal ( pre, i );
					if ( ans < tmp ) ans = tmp;
				}
				pre = i;
			}
		}
		printf ( "Case %d: %d\n", t, ans );
	}
	return 0;
}

