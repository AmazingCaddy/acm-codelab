//#include <stdio.h>
//#include <string.h>
//
//#define  L       1003
//#define  QL      (L*L)
//#define  SPACE   '.'
//#define  PRISON  'P'
//#define  GHOST   'G'
//#define  UN_MARK '*'
//
//char room[ L ][ L ], prison[ L ][ L ];
//int r, c, qi[ QL ], qj[ QL ], qh, qt;
//int DI[ ] = { 1, 0, -1, 0, 1, -1, -1, 1 };
//int DJ[ ] = { 0, -1, 0, 1, -1, -1, 1, 1 };
//
//void mark_prison( int i, int j ){
//	int k, i0, j0;
//	if( ( prison[ i ][ j ] = room[ i ][ j ] ) == PRISON ){
//		return;
//	}
//	qh = 0;
//	qt = 1;
//	qi[ 0 ] = i;
//	qj[ 0 ] = j;
//	while( qh < qt ){
//		i = qi[ qh ];
//		j = qj[ qh ];
//		++qh;
//		for( k = 0; k < 4; ++k ){
//			i0 = i + DI[ k ];
//			j0 = j + DJ[ k ];
//			if( ( 0 <= i0 ) && ( i0 < r ) && ( 0 <= j0 ) && ( j0 < c ) && ( prison[ i0 ][ j0 ] == UN_MARK ) ){
//				if( ( prison[ i0 ][ j0 ] = room[ i0 ][ j0 ] ) != PRISON ){
//					qi[ qt ] = i0;
//					qj[ qt ] = j0;
//					++qt;
//				}
//			}
//		}
//	}
//}
//
//int fill_count( int i, int j ){
//	int k, i0, j0;
//	prison[ i ][ j ] = UN_MARK;
//	qh = 0;
//	qt = 1;
//	qi[ 0 ] = i;
//	qj[ 0 ] = j;
//	while( qh < qt ){
//		i = qi[ qh ];
//		j = qj[ qh ];
//		++qh;
//		for( k = 0; k < 8; ++k ){
//			i0 = i + DI[ k ];
//			j0 = j + DJ[ k ];
//			if( ( 0 <= i0 ) && ( i0 < r ) && ( 0 <= j0 ) && ( j0 < c ) && ( prison[ i0 ][ j0 ] == PRISON ) ){
//				prison[ i0 ][ j0 ] = UN_MARK;
//				qi[ qt ] = i0;
//				qj[ qt ] = j0;
//				++qt;
//			}
//		}
//	}
//	return qt;
//}
//
//int main(){
//	int i, j, t, ans;
//	while( ~scanf( "%d%d%*c", &r, &c ) ){
//		for( i = 0; i < r; ++i ){
//			gets( room[ i ] );
//		}
//
//		memset( prison, UN_MARK, sizeof( prison ) );
//		for( i = 0; i < r; ++i ){
//			if( prison[ i ][ 0 ] == UN_MARK ){
//				mark_prison( i, 0 );
//			}
//			if( prison[ i ][ c - 1 ] == UN_MARK ){
//				mark_prison( i, c - 1 );
//			}
//		}
//		for( j = 0; j < c; ++j ){
//			if( prison[ 0 ][ j ] == UN_MARK ){
//				mark_prison( 0, j );
//			}
//			if( prison[ r - 1 ][ j ] == UN_MARK ){
//				mark_prison( r - 1, j );
//			}
//		}
//
//		for( i = 0; i < r; ++i ){
//			for( j = 0; j < c; ++j ){
//				if( prison[ i ][ j ] == UN_MARK ){
//					prison[ i ][ j ] = ( room[ i ][ j ] == PRISON ? GHOST : SPACE );
//				}
//			}
//		}
//
//		ans = 0;
//		for( i = 0; i < r; ++i ){
//			for( j = 0; j < c; ++j ){
//				if( prison[ i ][ j ] == PRISON ){
//					t = fill_count( i, j );
//					if( t > ans ){
//						ans = t;
//					}
//				}
//			}
//		}
//		printf( "%d\n", ans );
//	}
//	return 0;
//}
