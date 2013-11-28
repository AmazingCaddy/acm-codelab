#include<iostream>
#include<string>
#include<queue>
#define MAXN 8
using namespace std;
struct NODE
{
	int step,x,y;
};
int dir[8][2]={ {-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1} };
bool visit[MAXN][MAXN];

int bfs( int x1, int y1, int x2, int y2 )
{
	queue<NODE> que;
	NODE head,temp;
	int i,x,y,step,nx,ny;
	head.x=x1;head.y=y1;head.step=0;
	visit[x1][y1]=true;
	que.push(head);
	while( !que.empty( ) )
	{
		temp=que.front( );
		que.pop( );
		x=temp.x;y=temp.y;step=temp.step;
		for( i=0; i<8; i++ )
		{
			nx=x+dir[i][0];ny=y+dir[i][1];
			if( !visit[nx][ny] && nx<8 && nx>=0 && ny<8 && ny>=0 )
			{
				if( !( nx==x2 && ny==y2 ) )
				{
					temp.x=nx;
					temp.y=ny;
					temp.step=step+1;
					que.push(temp);
					visit[nx][ny]=true;
				}
				else return step+1;
			}
		}
	}
	return 0;
}

int main ()
{
	int x1,x2,y1,y2;
	string str1,str2;
	while( cin>>str1>>str2 )
	{
		x1=str1[0]-'a';y1=str1[1]-'1';
		x2=str2[0]-'a';y2=str2[1]-'1';
		memset( visit, false, sizeof(visit) );
		cout<<"To get from"<<" "<<str1<<" to "<<str2<<" takes "
			<<bfs(x1,y1,x2,y2)<<" knight moves."<<endl;
	}
	return 0;
}