import java.util.Scanner;
import java.math.BigDecimal;

public class Main {
	public static void main( String argc[]) {
		new Solve();
	}	
}

class Solve {
	static int maxn = 15;
	int dfa[ ][ ] = new int [ maxn ][ maxn ];
	int pattern[ ] = new int [ maxn ];
	int mat[ ][ ] = new int [ maxn ][ 26 ];
	int a[ ][ ] = new int [ maxn ][ maxn ];
	int b[ ] = new int [ maxn ];
	BigDecimal A[ ][ ] = new BigDecimal[ maxn ][ maxn ];
	BigDecimal B[ ] = new BigDecimal[ maxn ];
	
	int gauss_cpivot( int n ) {
		int i, j, k, row = -1;
		BigDecimal maxp, t;
		for ( k = 0; k < n; k++ ) {
			for( maxp = BigDecimal.ZERO, i = k; i < n; i++ ) {
				if( A[ i ][ k ].compareTo( maxp ) > 0 ) {
					row = i;
					maxp = A[ row ][ k ];
				}
			}
			if( maxp.equals(BigDecimal.ZERO) ) {
				return 0;
			}
			if( row != k ) {
				for( j = k; j < n; j++ ) {
					t = A[ k ][ j ];
					A[ k ][ j ] = A[ row ][ j ];
					A[ row ][ j ] = t;
				}
				t = B[ k ]; 
				B[ k ] = B[ row ]; 
				B[ row ] = t;
			}
			for( j = k + 1; j < n; j++ ) {
				A[ k ][ j ] = A[ k ][ j ].divide( maxp );
				for( i = k + 1; i < n; i++ ) {
					A[ i ][ j ] = A[ i ][ j ].subtract( A[ i ][ k ].multiply( A[ k ][ j ] ) );
				}
			}
			B[ k ] = B[ k ].divide( maxp );
			for( i = k + 1; i < n; i++ ) {
				B[ i ] = B[ i ].subtract( B[ k ].multiply( A[ i ][ k ] ) );
			}
		}
		for( i = n - 1; i >= 0; i-- ) {
			for( j = i + 1; j < n; j++ ) {
				B[ i ] = B[ i ].subtract( A[ i ][ j ].multiply( B[ j ] ) );
			}
		}
		return 1;
	}
	
	void init( String buf ) {
		int len = buf.length();
		for( int i = 0; i < len; i++ ) {
			pattern[ i + 1 ] = buf.charAt( i ) - 'A';
		}
		for( int i = 1; i <= len; i++ ) {
			for( int j = i; j <= len; j++ ) {
				dfa[ j ][ i ] = pattern[ i ];
			}
		}
	}
	
	boolean match( int n, int m ) {
		for( int i = n, j = m + 1; i > 0; i--, j-- ) {
			if( dfa[ n ][ i ] != dfa[ m ][ j ] ) {
				return false;
			}
		}
		return true;
	}

	int match( int n ) {
		for( int i = n; i > 0; i-- ) {
			if( match( i, n ) ) {
				return i;
			}
		}
		return 0;
	}
	
	void solve( int n, int len ) {
		for( int i = 0; i < len; i++ ) {
			for( int j = 0; j < n; j++ ) {
				if( j == pattern[ i + 1 ] ) {
					mat[ i ][ j ] = i + 1;
				}
				else {
					dfa[ i ][ i + 1 ] = j;
					mat[ i ][ j ] = match( i );
				}
			}
		}
		for( int i = 0; i < maxn; i++ ) {
			b[ i ] = 0;
			for( int j = 0; j < maxn; j++ ) {
				a[ i ][ j ] = 0;
			}
		}
		a[ len ][ len ] = 1;
		b[ len ] = 0;
		for( int i = 0; i < len; i++ ) {
			a[ i ][ i ] = n;
			b[ i ] = n;
			for( int j = 0; j < n; j++ ) {
				a[ i ][ mat[ i ][ j ] ] -= 1;
			}
		}
		len++;
		for( int i = 0; i < len; i++ ) {
			B[ i ] = BigDecimal.valueOf( b[ i ] );
		//	B[ i ].setScale( 50, BigDecimal.ROUND_HALF_UP );
			for( int j = 0; j < len; j++ ) {
				A[ i ][ j ] = BigDecimal.valueOf( a[ i ][ j ] );
			//	A[ i ][ j ].setScale( 100, BigDecimal.ROUND_HALF_UP );
			}
		}
		gauss_cpivot( len );
		System.out.println( B[ 0 ] );
	}
	
	Solve() {
		Scanner cin = new Scanner( System.in );
		int cas = cin.nextInt();
		for( int t = 1; t <= cas; t++ ) {
			if( t > 1 ) {
				System.out.println( "" );
			}
			int n = cin.nextInt( );
			String buf = cin.next( );
			init( buf );
			System.out.println( "Case " + t + ":" );
			solve( n, buf.length( ) );
		}
	}
}
