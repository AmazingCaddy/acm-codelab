//求最大子阵和,复杂度O(n^3)
//传入阵的大小m,n 和内容mat[][]
//返回最大子阵和,重载返回子阵位置(maxsum=list[s1][s2]+...+list[e1][e2])
//可更改元素类型
#include<iostream>
#define MAXN 1001
#define INF 100000
typedef int elem_t;
using namespace std;
elem_t mat[MAXN][MAXN+1],matsum[MAXN][MAXN+1];
elem_t maxsum( int m, int n )
{
	elem_t ret,sum;
	int i,j,k;
	for( i=0; i<m; i++ )
		for( matsum[i][j=0]=0; j<n; j++ )
			matsum[i][j+1]=matsum[i][j]+mat[i][j];
	for( ret=mat[0][j=0]; j<n; j++ )
		for( k=j; k<n; k++ ) 
			for( sum=0, i=0; i<m; i++ )
				sum=(sum>0?sum:0)+matsum[i][k+1]-matsum[i][j], ret=(sum>ret?sum:ret);
	return ret;
}
int main( )
{
	int m,n,ans,i,j;
	while( scanf("%d%d",&m,&n) != EOF )
	{
		for( i=0; i<m; i++ )
		{
			for( j=0; j<n; j++ )
			{
				scanf("%d",&mat[i][j]);
				if( mat[i][j]==0 )mat[i][j]=-INF;
			}
		}
		ans=maxsum( m, n );
		printf("%d\n",ans);
	}
	return 0;
}