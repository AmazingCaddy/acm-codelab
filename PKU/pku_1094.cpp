#include<iostream>
#define SIZE 27
#define MAXN 500
using namespace std;

struct NODE 
{
	int V;
	NODE *next;
};
NODE MAP[SIZE];
int degree[SIZE];
bool visit[SIZE];
int num,cnt;
char que[SIZE];

void insert( int u, int v )
{
	NODE *p=new NODE;
	p->V=v;
	p->next=MAP[u].next;
	MAP[u].next=p;
}

void Init( )
{
	int i;
	for( i=0; i<SIZE; i++ )
	{
		degree[i]=0;
		visit[i]=false;
		MAP[i].next=NULL;
	}
}

int topsort( int nodenum )
{
	int stack[SIZE],top=-1,i,flag,temp[SIZE];
	NODE *p;
	cnt=0;
	flag=-2;
	//先找出初始状态下入度为0的点
	//如果有多个点则标志为-1
	for( i=0; i<SIZE; i++ )
	{
		temp[i]=degree[i];
		if( temp[i]==0 && visit[i] )
		{
			stack[++top]=i;
			if( top>0 )flag=-1;
		}
	}
	//记录序列，并判断是否有多个解存在
	while( top != -1 )
	{
		que[cnt++]=(char)(stack[top]+'A');
		p=MAP[stack[top--]].next;
		while( p )
		{
			temp[p->V]--;
			if( temp[p->V]==0 )
			{
				stack[++top]=p->V;
				if( top>0 )flag=-1;
			}
			p=p->next;
		}
	}
	if( cnt<nodenum )//有环存在，则返回0
		return 0;
	if( cnt==num && flag != -1 )//能确定序列，返回1
		flag=1;
	return flag;
}

int main( )
{
	char str[5];
	int u,v,i,n,c,ans,flag;
	bool circle;
	while( 1 )
	{
		scanf("%d%d",&num,&n);
		if( num==0 && n==0 )break;
		Init( );
		c=0;
		ans=1000;
		flag=-2;
		circle=false;
		for( i=1; i<=n; i++ )
		{
			scanf("%s",str);
			if( flag==1 || circle )continue;
			u=str[0]-'A';v=str[2]-'A';
			degree[v]++;
			if( !visit[u] )visit[u]=true,c++;
			if( !visit[v] )visit[v]=true,c++;
			insert( u, v );
			if( flag!=1 )
			{
				flag=topsort( c );
				if( flag==0 && ans>i )
					circle=true,ans=i;
				else if( flag==1 )ans=i;
			}
		}
		if( flag==1 )//先确定有解
		{
			que[cnt]=0;
			printf("Sorted sequence determined after %d relations: %s.\n",ans,que);
		}
		else if( circle )//有环
			printf("Inconsistency found after %d relations.\n",ans);
		else printf("Sorted sequence cannot be determined.\n");//不能确定  
	}
	return 0;
}