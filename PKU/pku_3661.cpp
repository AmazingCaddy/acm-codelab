//  dp[i][j]:��i����ƣ�Ͷ�Ϊjʱ�����·��ֵ
//  ת�Ʒ��̣�
//  dp[i][j] = dp[i-1][j-1] + distance[i] ( j > 0 )
//  dp[i][0] = max ( dp[i-1][0], dp[i-j][j]( i-j >= j && j <= M ) )
//  i-j>=j ��Ϊ��i-j����ƣ�Ͷ�Ϊj������i���ӣ�ƣ�Ͷȱ���Ϊ0��
//  ����Ϊѡ����Ϣ��������Ϣ��ƣ�Ͷ�Ϊ0Ϊֹ

#include<iostream>
const int SIZE_T = 10001;
const int SIZE_M = 501;
int dp[SIZE_T][SIZE_M];
int T, M, dist[SIZE_T];
using namespace std;
void Solve( )
{
	int i, j;
	for ( i = 0; i <= M; i++ )   //��0���ӣ�ƣ�Ͷ�Ϊi�����·����Ϊ0
		dp[0][i] = 0;
	for ( i = 1; i <= T; i++ )
	{
		dp[i][0] = dp[i-1][0];
		for ( j = 1; i-j >= j && j <= M; j++ )
			dp[i][0] = ( dp[i][0] > dp[i-j][j] ? dp[i][0] : dp[i-j][j] );
		for ( j = 1; j <= M; j++ )
			dp[i][j] = dp[i-1][j-1] + dist[i]; 
	}
	printf("%d\n", dp[T][0]);
}

int main( )
{
	int i;
	scanf("%d %d", &T, &M );
	for ( i = 1; i <= T; i++ )
		scanf("%d", &dist[i]);
	Solve( );
	return 0;
}