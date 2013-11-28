#include<iostream>
#include<string>
using namespace std;
const int maxn = 1003;
int dp[maxn][maxn];
int max( int a, int b ){ return ( a > b ? a : b ); }
int main( )
{
	int i, j, len1, len2;
	string str1,str2;
	while( cin >> str1 >> str2 )
	{
		memset( dp, 0, sizeof( dp ) );
		len1 = str1.size( );
		len2 = str2.size( );
		for( i = 1; i <= len1; i++ )
		{
			for( j = 1; j <= len2; j++ )
			{
				if( str1[i-1] == str2[j-1] )dp[i][j] = dp[i-1][j-1] + 1;
				else dp[i][j] = max( dp[i][j-1], dp[i-1][j] );
			}
		}
		printf("%d\n",dp[len1][len2]);
	}
	return 0;
}