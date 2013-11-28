#include<iostream>
using namespace std;
#define MAX 200
#define maxn 41000

int que[maxn][3];
int queway[maxn];
bool mark[MAX][MAX];
int n,m,count;
char mat[MAX][MAX];
int flag;

const int dir[4][2]={{-1,0},{0,-1},{0,1},{1,0}};

void print(int x)
{
	if ( x==1 )
	{
		printf("%d %d\n",que[x][0],que[x][1]);
		return;
	}
	print(queway[x]);
	printf("%d %d\n",que[x][0],que[x][1]);
}

int bfs(int y,int x)
{
	int qb=0,qe=1;
	que[qe][0]=y;que[qe][1]=x;que[qe][2]=0;
	while( qb!=qe )
	{
		qb=qb+1;
		y=que[qb][0];x=que[qb][1];
		mark[y][x]=true;
		for( int i=0; i<4; i++ )
		{
			int ny=dir[i][0]+y,nx=dir[i][1]+x;
			if( ny>=0 && nx>=0 && ny<n && nx<m )
			{
				if( mat[ny][nx]=='.' && mark[ny][nx]==false )
				{
					mark[ny][nx]=true;
					qe+=1;
					que[qe][0]=ny;
					que[qe][1]=nx;
					que[qe][2]=que[qb][2]+1;
					queway[qe]=qb;
				}
				if( mat[ny][nx]=='E' && mark[ny][nx]==false )
				{
					qe+=1;
					queway[qe]=qb;
					que[qe][0]=ny;
					que[qe][1]=nx;
					flag=qe;
					return que[qb][2]+1;
				}

			}
		}

	}
	return -1;
}

int main()
{
	int i,j,temp;
	scanf("%d%d",&n,&m);

	for( i=0; i<n; i++ )
		scanf("%s",mat[i]);

	for( i=0; i<n; i++ )
	{
		for( j=0; j<m; j++ )
			if( mat[i][j]=='S')break;

		if(mat[i][j]=='S')break;
	}

	temp=bfs(i,j);
	printf("%d\n",temp);
	if(temp!=-1)print(flag);

	return 0;
}

