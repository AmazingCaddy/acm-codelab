#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

string h[15][4], a[15][4];
string yes = "yes", no = "no";

// win = 1 home wins, win = 0 away wins
void solve( int & win, int & goal1, int & goal2 )
{
	int home[15], away[15];
	home[0] = 0, away[0] = 0;
	int aa = 0;
	for( int i = 1; i <= 5; i++ )
	{
		home[i] = home[i-1] + ( h[i][0] == yes ? 1 : 0 );
		if( i <= 3 )away[i] = away[i-1] + ( a[i][0] == yes ? 1 : 0 );
	}
	aa = away[3];
	if( home[3] == 3 && aa == 0 )
	{
		win = 1, goal1 = home[3], goal2 = aa;
		return ;
	}
	//aa = aa + ( a[3][0] == yes ? 1 : 0 ); 
	if( home[3] == 0 && aa == 3 )
	{
		win = 0, goal1 = home[3], goal2 = aa;
		return;
	}
	// 4 球
	if( home[4] - aa > 2 )
	{
		win = 1, goal1 = home[4], goal2 = aa;
		return ;
	}
	if( aa - home[4] >= 2 )
	{
		win = 0, goal1 = home[4], goal2 = aa;
		return;
	}
	aa = aa + ( a[4][0] == yes ? 1 : 0 );
	if( home[4] - aa >= 2 )
	{
		win = 1, goal1 = home[4], goal2 = aa;
		return;
	}
	if( aa - home[4] >= 2 )
	{
		win = 0, goal1 = home[4], goal2 = aa;
		return ;
	}
	// 5 球
	if( home[5] - aa >= 2 )
	{
		win = 1, goal1 = home[5], goal2 = aa;
		return ;
	}
	if( aa > home[5] )
	{
		win = 0, goal1 = home[5], goal2 = aa;
		return ;
	}
	aa = aa + ( a[5][0] == yes ? 1 : 0 );
	if( home[5] > aa )
	{
		win = 1, goal1 = home[5], goal2 = aa;
		return ;
	}
	if( aa > home[5] )
	{
		win = 0, goal1 = home[5], goal2 = aa;
		return ;
	}
	int cnt1 = home[5], cnt2 = aa;
	for( int i = 6; i <= 11; i++ )
	{
		if( h[i][0] == yes && a[i][0] == no )
		{
			cnt1++;
			win = 1, goal1 = cnt1, goal2 = cnt2;
			return;
		}
		if( h[i][0] == no && a[i][0] == yes )
		{
			cnt2++;
			win = 0, goal1 = cnt1, goal2 = cnt2;
			return;
		}
		if( h[i][0] == a[i][0] )
		{
			cnt1 = cnt1 + ( h[i][0] == yes ? 1 : 0 );
			cnt2 = cnt1;
		}
	}
	for( int j = 1; j < 3; j++ )
	{
		for( int i = 1; i <= 11; i++ )
		{
			if( h[i][j] == yes && a[i][j] == no )
			{
				cnt1++;
				win = 1, goal1 = cnt1, goal2 = cnt2;
				return;
			}
			if( h[i][j] == no && a[i][j] == yes )
			{
				cnt2++;
				win = 0, goal1 = cnt1, goal2 = cnt2;
				return;
			}
			if( h[i][j] == a[i][j] )
			{
				cnt1 = cnt1 + ( h[i][j] == yes ? 1 : 0 );
				cnt2 = cnt1;
			}
		}
	}
}

int main( )
{
	int t, win, goal1, goal2;
	scanf("%d",&t);
	for( int p = 1; p <= t; p++ )
	{
		for( int i = 1; i <= 11; i++ )
			for( int j = 0; j < 3; j++ )
				cin>>h[i][j];
		for( int i = 1; i <= 11; i++ )
			for( int j = 0; j < 3; j++ )
				cin>>a[i][j];
		solve( win, goal1, goal2 );
		printf("Match %d:\n",p);
		if( win == 1 )
		{
			printf("Winner: home\n");
			printf("Score: %d:%d\n",goal1,goal2);
		}
		else
		{
			printf("Winner: away\n");
			printf("Score: %d:%d\n",goal1,goal2);
		}
	}
	return 0;
}
