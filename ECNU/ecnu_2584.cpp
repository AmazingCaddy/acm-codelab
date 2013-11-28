//#include<iostream>
//#include<string>
//using namespace std;
//#define MAXN 8
//#define maxn 80
//int dir[8][2]={{-1,-2},{1,-2},{-2,-1},{2,-1},{-2,1},{2,1},{-1,2},{1,2}};//°Ë¸ö·½Ïò
//bool visit[MAXN][MAXN];
//int que[maxn][3];
//
//int bfs( int y, int x ,int z, int w )
//{
//	int qb=0,qe=1;
//	memset( visit, false, sizeof( visit ) );
//	memset( que, 0, sizeof(que) );
//	que[qe][0]=y;que[qe][1]=x;que[qe][2]=0;
//	while( qb!=qe )
//	{
//		qb+=1;
//		y=que[qb][0];x=que[qb][1];
//		visit[y][x]=true;
//		for( int i=0; i<8; i++ )
//		{
//			int ny=dir[i][0]+y,nx=dir[i][1]+x;
//			if( ny>=0&& nx>=0 && ny<MAXN && nx<MAXN )
//			{
//				if( !(ny==z && nx==w) && !visit[ny][nx] )
//				{
//					visit[ny][nx]=true;
//					qe+=1;
//					que[qe][0]=ny;
//					que[qe][1]=nx;
//					que[qe][2]=que[qb][2]+1;
//				}
//				if( ny==z && nx==w && !visit[ny][nx] )
//				{
//					visit[ny][nx]=true;
//					qe+=1;
//					que[qe][0]=ny;
//					que[qe][1]=nx;
//					que[qe][2]=que[qb][2]+1;
//					return que[qe][2];
//				}
//			}
//		}
//	}
//}
//
//int main()
//{
//	int t,a,b,c,a1,b1,c1;
//	int step1,step2,step3;
//	string ch1,ch2,ch3;
//	scanf("%d",&t);
//	while( t-- )
//	{
//		cin>>ch1>>ch2>>ch3;
//		a=ch1[0]-'a';
//		b=ch2[0]-'a';
//		c=ch3[0]-'a';
//		a1=ch1[1]-'1';
//		b1=ch2[1]-'1';
//		c1=ch3[1]-'1';
//		step1=bfs( b, b1, c, c1 );
//		step2=bfs( a, a1, b, b1 );
//		step3=bfs( a, a1, c, c1 );
//		printf("%d\n",step1+(step2>step3?step3:step2));
//	}
//	return 0;
//}

#include<iostream>
#include<queue>
using namespace std;
#define MAXN 110
struct NODE
{
	int i,j,state,floor;
};
bool vis[10][10][4];
int mv[8][2]={-2, -1, -2, 1, 2, -1, 2, 1, -1, -2, 1, -2, -1, 2 , 1, 2 };
int rx,ry,qx,qy,kx,ky;
int bfs ( )
{
	memset(vis,false,sizeof(vis));
	NODE head,temp;
	queue<NODE> que;
	temp.floor=0,temp.i=kx,temp.j=ky,temp.state=0;
	vis[kx][ky][0]=true;
	que.push(temp);
	int i,tm,tn,state;
	while ( !que.empty() )
	{
		head=que.front();
		que.pop();
		for ( i=0 ; i<8 ; i++ )
		{
			tm=head.i+mv[i][0],tn=head.j+mv[i][1];
			if ( tm>=0 && tm<8 && tn>=0 && tn<8 )
			{
				state=head.state;
				if ( tm==rx && tn==ry && !vis[tm][tn][state] )
				{
					//if ( state%2 )
					//	continue;
					state|=1;
					if ( state==3 )
						return head.floor+1;
					temp.i=tm,temp.j=tn,temp.state=state,temp.floor=head.floor+1;
					que.push(temp);
					vis[tm][tn][state]=true;
				}
				else
					if ( tm==qx && tn==qy && !vis[tm][tn][state] )
					{
						//if ( state&2 )
						//	continue;
						state|=2;
						if ( state==3 )
							return head.floor+1;
						temp.i=tm,temp.j=tn,temp.state=state,temp.floor=head.floor+1;
						que.push(temp);
						vis[tm][tn][state]=true;
					}
					else
					{
						if ( vis[tm][tn][state] )
							continue;
						temp.i=tm,temp.j=tn,temp.state=state,temp.floor=head.floor+1;
						vis[tm][tn][state]=true;
						que.push(temp);
					}
			}
		}
	}
	return -1;
}
int main ( )
{
	int cas,res;
	char pos[3];
	scanf("%d",&cas);
	while ( cas-- )
	{
		scanf("%s",pos);
		kx=7-(pos[0]-'a');
		ky=pos[1]-'1';
		scanf("%s",pos);
		qx=7-(pos[0]-'a');
		qy=pos[1]-'1';
		scanf("%s",pos);
		rx=7-(pos[0]-'a');
		ry=pos[1]-'1';
		res=bfs();
		printf("%d\n",res);
	}
}
