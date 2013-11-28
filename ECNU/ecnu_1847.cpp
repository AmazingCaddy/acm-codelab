#include<iostream>
#include<queue>
#define MAXN 32
using namespace std;
bool vis[MAXN][MAXN];
char mat[MAXN][MAXN];
int c,n,m;
struct node
{
	int x,y;
};
int dir[4][2]={{-1,0},{0,-1},{0,1},{1,0}};
void BFS( int i, int j )
{
	queue<node> que;
	node temp;
	int x,y,nx,ny;
	memset( vis, false, sizeof(vis) );
	temp.x=i;
	temp.y=j;
	que.push(temp);
	vis[i][j]=true;
	while( !que.empty( ) )
	{
		temp=que.front( );
		que.pop( );
		x=temp.x;
		y=temp.y;
		for( i=0; i<4; i++ )
		{
			nx=dir[i][0]+x;
			ny=dir[i][1]+y;
			if( !vis[nx][ny] && mat[nx][ny]=='.' && nx<m && nx>=0 && ny>=0 && ny<n )
			{
				vis[nx][ny]=true;
				c++;
				temp.x=nx;
				temp.y=ny;
				que.push(temp);
			}
		}
	}
}

int main( )
{
	int mi,mj,j,i;
	//freopen("in.txt","r",stdin);
	//freopen("answer.txt","w",stdout);
	while( scanf("%d%d",&m,&n) && (n||m) )
	{
		getchar( );
		for( i=0; i<m; i++ )
		{
			scanf("%s",&mat[i]);
			for( j=0; j<n; j++ )
				if( mat[i][j]=='M' )
					mi=i,mj=j;
		}
		c=1;
		BFS( mi, mj );
		printf("%d\n",c);
	}
	return 0;
}

//#include<iostream>
//#include<cstdlib>
//#include<ctime>
//#define MAXN 1000
//using namespace std;
//
//int main( )
//{
//	int p,q,i,j,t=MAXN,x,a,b;
//	freopen("in.txt","w",stdout);
//	srand(unsigned(time(0)));
//	while( t-- )
//	{
//		p=rand()%30+1;
//		q=rand()%30+1;
//		a=rand()%p;
//		b=rand()%q;
//		printf("%d %d\n",p,q);
//		for( i=0; i<p; i++ )
//		{
//			for( j=0; j<q; j++ )
//			{
//				if( i==a && j==b )printf("M");
//				else 
//				{
//					x=rand()%10;
//					if( x>=2 )printf(".");
//					else printf("#");
//				}
//			}
//			printf("\n");
//		}
//	}
//	return 0;
//}
