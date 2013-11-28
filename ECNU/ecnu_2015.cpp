#include<iostream>
#include<string>
#include<algorithm>
#define MAXN 102
#define MAXM 16
using namespace std;
struct node 
{
	string str;
	int R,C,DIS;
	char max[MAXM][MAXM];
	bool operator<( const node& a )
	{
		return DIS<a.DIS;
	}
	bool isroom( )
	{
		int i,j;
		if( max[0][0]=='0' && max[0][1]=='0' || max[0][C-1]=='0' && max[0][C-2]=='0' )
			return true;
		for( i=0; i<C; i++ )
			if( max[i][0]=='0' && max[i][1]=='0' && max[i-1][0]=='0' || 
				max[i][C-1]=='0' && max[i][C-2]=='0' && max[i-1][C-1]=='0')
				return true;
		for( i=1; i<R; i++ )
			for( j=1; j<C-1; j++ )
				if( max[i][j-1]=='0' && max[i][j]=='0' && max[i][j+1]=='0' && max[i-1][j]=='0' )
					return true;
		return false;
	}
};
node Class[MAXN];

int main( )
{
	int n,i,j;
	while( scanf("%d",&n) != EOF )
	{
		for( i=0; i<n; i++ )
		{
			cin>>Class[i].str;
			scanf("%d%d%d",&Class[i].DIS,&Class[i].R,&Class[i].C);
			for( j=0; j<Class[i].R; j++ )
				scanf("%s",Class[i].max[j]);
		}
		sort( Class, Class+n );
		for( i=0; i<n; i++ )
			if( Class[i].isroom( ) )break;
		if( i==n )printf("Bad Luck,Rocker!\n");
		else cout<<Class[i].str<<endl;
	}
	return 0;
}