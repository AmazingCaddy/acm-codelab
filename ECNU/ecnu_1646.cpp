#include<iostream>
#include<queue>
#define N 10000
using namespace std;
struct NODE
{
	int state,step;
};
bool prime[10001];
int n,start,end;
void c_prime( )
{
	memset(prime,true,sizeof(prime));
	prime[0]=prime[1]=false;
	for ( int i = 2 ; i<=100 ; i++ )
		for ( int j=2 ; i*j<=10000 ; j++ )
			prime[i*j]=false;
}
void bfs ( )
{
	int j,tt;
	NODE head,temp;
	queue<NODE> que;
	bool vis[N];
	if ( start==end )
	{
		printf("0\n");
		return ;
	}
	memset(vis,false,sizeof(vis));
	head.state=start;
	head.step=0;
	vis[start]=true;
	que.push(head);
	while ( !que.empty() )
	{
		head=que.front();
		que.pop();
		for ( j=1; j<=9; j+=2 )    //个位
		{
			tt=head.state-head.state%10+j;
			if ( tt==end )
			{
				printf("%d\n",head.step+1);
				return;
			}
			if ( prime[tt] && !vis[tt] )
			{
				vis[tt]=true;
				temp.state=tt,temp.step=head.step+1;
				que.push(temp);
			}
		}
		for ( j=0; j<=9; j++ )    //十位
		{
			tt=head.state-head.state%100+head.state%10+j*10;
			if ( tt==end )
			{
				printf("%d\n",head.step+1);
				return;
			}
			if ( prime[tt] && !vis[tt] )
			{
				vis[tt]=true;
				temp.state=tt,temp.step=head.step+1;
				que.push(temp);
			}
		}
		for ( j=0; j<=9; j++ )   //百位
		{
			tt=head.state-head.state%1000+head.state%100+j*100;
			if ( tt==end )
			{
				printf("%d\n",head.step+1);
				return;
			}
			if ( prime[tt] && !vis[tt] )
			{
				vis[tt]=true;
				temp.state=tt,temp.step=head.step+1;
				que.push(temp);
			}
		}
		for ( j=1; j<=9; j++ )   //千位
		{
			tt=head.state%1000+1000*j;
			if ( tt==end )
			{
				printf("%d\n",head.step+1);
				return;
			}
			if ( prime[tt] && !vis[tt] )
			{
				vis[tt]=true;
				temp.state=tt,temp.step=head.step+1;
				que.push(temp);
			}
		}
	}
	printf("Impossible.\n");
}
int main ( )
{
	int n;
	scanf("%d\n",&n);
	c_prime();
	while ( n-- )
	{
		scanf("%d%d",&start,&end);
		bfs();
	}
}
