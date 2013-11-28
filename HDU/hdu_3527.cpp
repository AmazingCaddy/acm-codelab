////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 546711990
////Nickname: AmazingCaddy
////Run ID: 
////Submit time: 2010-08-14 12:50:27
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3527
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cstring>
#include<map>
using namespace std;
const int maxn = 103;
vector<string> YX;
map<string,int> ALL, XY;
int yx[10003];
int main( )
{
	int a, b, c;
	char ch[maxn];
	while( scanf("%d%d%d",&a,&b,&c) != EOF )
	{
		ALL.clear( );
		YX.clear( );
		XY.clear( );
		for( int i = 0; i < a; i++ )
		{
			scanf("%s",ch);
			string str( ch );
			ALL[str] = i;
		}
		for( int i = 0; i < b; i++ )
		{
			scanf("%s",ch);
			string str( ch );
			YX.push_back( str );
			yx[i] = 1;
		}
		for( int i = 0; i < c; i++ )
		{
			scanf("%s",ch);
			string str( ch );
			XY[str] = i;
		}
		int cnt = b;
		for( int i = 0; i < b; i ++ )
		{
			if( ALL.find( YX[i] ) == ALL.end( ) )
				yx[i] = 0, cnt --;
		}
		for( int i = 0; i < b; i++ )
		{
			if( yx[i] && XY.find( YX[i] ) != XY.end( ) )
				yx[i] = 0, cnt--;
		}
		if( cnt == 0 ) printf("No enemy spy\n");
		else
		{
			int i;
			for( i = 0; i < b; i++ )
			{
				if( yx[i] )
				{
					cout << YX[i];
					break;
				}
			}
			for( int j = i + 1; j < b; j++ )
			{
				if( yx[j] )
					cout<<" "<<YX[j];
			}
			printf("\n");
		}
	}
	return 0;
}
