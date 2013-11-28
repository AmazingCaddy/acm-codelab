//  �о������ݲ�̫�����Զ���ö������߳������ȴ������Ŀ��Ը�ֵΪ����
//  ��ʾ���Կ����õ绰��˾��Ǯ�������ĸ�ֵΪ������Ȼ����ͨ������INF������󣩣���
//  Ȼ�������·��
//  �� dist[n] <= k ��ʾ���ڵ�ǰ���߷��������ڸó��ȵĲ�����k����
//  ����ȫ���ɵ绰��˾��Ǯ����С�ó��ȣ�
//  ���򣬱�ʾ�ó���̫С�ˣ���Ϊ���ȴ�Ķ���k��.�绰��˾������ô�࣬
//  ֻ�����ӳ��ȣ��Լ�����Ǯ�¡�

#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#define MAXN 1005
#define M 10005
#define INF 1<<29
using namespace std;
struct node 
{
	int u;
	int d;
};
vector<node> mat[MAXN];
queue<int> que;
bool inque[MAXN];
int dist[MAXN];
int n,p,k;
int ee[M],e[M];

bool SPFA( int len )
{
	unsigned int i,j,x,t;
	node temp;
	vector<node> mp[MAXN];
	memset( inque, false, sizeof(inque) );
	for( i=1; i<=n; i++ )
	{
		for( j=0; j<mat[i].size( ); j++ )
		{
			temp.u=mat[i][j].u;
			temp.d=mat[i][j].d > len ? 1 : 0 ;
			mp[i].push_back( temp );
		}
		dist[i]=INF;
	}
	que.push( 1 );
	dist[1]=0;
	inque[1]=true;
	while( !que.empty( ) )
	{
		x=que.front( );
		que.pop( );
		inque[x]=false;
		for( i=0; i<mp[x].size( ); i++ )
		{
			if( dist[x]+mp[x][i].d<dist[t=(mp[x][i].u)] )
			{
				dist[t]=dist[x]+mp[x][i].d;
				if( !inque[t] )
				{
					que.push( t );
					inque[t]=true;
				}
			}
		}
	}
	return dist[n]<=k;
}

int main( )
{
	int i,x,y,d;
	int l,r,mid,cnt;
	node temp;
	while( scanf("%d%d%d",&n,&p,&k) != EOF )
	{
		for( i=1; i<MAXN; i++ )
			mat[i].clear( );
		for( i=1; i<=p; i++ )
		{
			scanf("%d%d%d",&x,&y,&d);
			temp.u=y;
			temp.d=d;
			mat[x].push_back( temp );
			temp.u=x;
			temp.d=d;
			mat[y].push_back( temp );
			e[i]=d;
		}
		e[0]=0;
		sort( e, e+p+1 );
		cnt=1;
		for( i=1; i<=p; i++ )
			if( e[i]!=e[i-1] )
				ee[cnt++]=e[i];
		l=0;r=cnt-1;
		while( l<=r )
		{
			mid=(l+r)>>1;
			if( SPFA(ee[mid]) ) r=mid-1;
			else l=mid+1;
		}
		if( SPFA(ee[l]) )printf("%d\n",ee[l]);
		else printf("-1\n");
	}
	return 0;
}


