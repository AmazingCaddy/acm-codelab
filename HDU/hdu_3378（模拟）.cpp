#include<iostream>
#include<map>
#include<string>
#define MAXN 103
using namespace std;
const int ZG=1,ZC=2,NJ=3,FZ=4;
map<int,string> role;
map<string,int> cnt;
bool vis[MAXN];
int main( )
{
	int point[MAXN];
	int t,n,m,i,x,y,zg,zc,nj,fz;
	string str,str1,str2;
	int win,killNJ;
	scanf("%d",&t);
	while( t-- )
	{
		role.clear( );
		cnt.clear( );
		scanf("%d%d",&n,&m);
		for( i=0; i<n; i++ )
		{
			cin>>str;
			role[i]=str;
			cnt[str]++;
		}
		memset( point, 0, sizeof(point) );
		memset( vis, false, sizeof(vis) );
		win = 0, killNJ = 0;
		for( i=0; i<m; i++ )
		{
			scanf("%d%d",&x,&y);
			if( win )continue;
			str1 = role[x], str2 = role[y];
			vis[y] = true;
			if( str1 != "NJ" )   extra points
			{
				if( str1 == "FZ" )  str1 is FZ
				{
					if( str2 == "ZG" ) point[x]+=2;
					else if( str2 != "FZ" ) point[x]++;
				}
				else if( str1 != "NJ" )  str1 is ZG or ZC
				{
					if( str2 == "FZ" || str2 == "NJ" ) point[x]++;
				}
			}
			cnt[str2]--;
			
			zg = cnt["ZG"], zc = cnt["ZC"], nj = cnt["NJ"], fz = cnt["FZ"];
			if( zg == 0 )
			{
				if( zc == 0 && fz == 0 && nj == 1 ) win = NJ;
				else win = FZ;
			}
			else if( zg == 1 )
			{
				if( zc > 0 && fz == 0 && nj == 0 ) win = ZC;
				else if( zc == 0 && fz == 0 && nj == 0 )
				{
					if( str2 == "NJ" ) 
					{
						killNJ = y;
					}
					win = ZG;
				}
			}
		}
		switch( win )
		{
		case ZG:
		case ZC:
			for( i=0; i<n; i++ )
			{
				str = role[i];
				if( str == "ZG" ) point[i] = point[i] + ( 4 + zc * 2 );
				if( str == "ZC" ) point[i] = point[i] + ( 5 + zc );
				if( str == "FZ" ) point[i] = 0;
				if( str == "NJ" )
				{
					if( i == killNJ ) point[i] = n;
					else point[i] = 0; 
				}
			}
			break;
		case FZ:
			for( i=0; i<n; i++ )
			{
				str = role[i];
				if( str == "ZG" || str == "ZC" ) point[i] = 0;
				if( str == "FZ" ) point[i] = point[i] + fz * 3;
				if( str == "NJ" )
				{
					if( !vis[i] ) point[i] = 1;
					else point[i] = 0;
				}
			}
			break;
		case NJ:
			for( i=0; i<n; i++ )
			{
				str = role[i];
				if( str == "ZG" ) point[i] = 1;
				if( str == "ZC" ) point[i] = 0;
				if( str == "FZ" ) point[i] = 0;
				if( str == "NJ" )
				{
					if( !vis[i] ) point[i] = 4 + 2 * n;
					else point[i] = 0;
				}
			}
			break;
		}
		for( i=0; i<n; i++ )
		{
			if( i != 0 )printf(" ");
			printf("%d",point[i]);
		}
		printf("\n");
	}
	return 0;
}