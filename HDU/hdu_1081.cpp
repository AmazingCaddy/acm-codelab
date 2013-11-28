//求最大子阵和,复杂度O(n^3)
#include<iostream>
using namespace std;
#define MAXN 103
typedef int elem_t;

elem_t maxsum( int m, int n, elem_t mat[][MAXN] )
{
	elem_t matsum[MAXN][MAXN+1], ret, sum;
	int i, j, k;
	for( i = 0; i < m; i++ )
		for( matsum[i][j=0] = 0; j < n; j++ )
			matsum[i][j+1] = matsum[i][j] + mat[i][j];
	for( ret = mat[0][j=0]; j < n; j++ )
		for( k = j; k < n; k++ )
			for( sum = 0, i = 0; i < m; i++ )
				sum = ( sum > 0 ? sum : 0 ) + matsum[i][k+1] - matsum[i][j], ret = ( sum > ret ? sum : ret );
	return ret;
}

int main( )
{
	int i, j, n, ans;
	int mat[MAXN][MAXN];
	while( scanf("%d",&n) != EOF )
	{
		for( i = 0; i < n; i++ )
			for( j = 0; j < n; j++ )
				scanf("%d",&mat[i][j]);
		ans = maxsum( n, n, mat );
		printf("%d\n",ans);
	}
	return 0;
}