#include<iostream>
#define MAXN 50000
using namespace std;
int father[MAXN],rank[MAXN];
bool visit[MAXN];
int num;
void inti_set( )
{
	int i;
	for( i=1; i<MAXN; i++ )
		father[i]=i,rank[i]=1;
}

int find_root( int p )
{
	if( father[p]!=p )
		father[p]=find_root( father[p] );
	return father[p];
}

void union_set( int p, int q )
{
	int a, b;
	a = find_root( p );
	b = find_root( q );
	if( a==b ) return;
	num++;
	if( rank[a] > rank[b] )
		father[b] = a;
	else if( rank[a] < rank[b] ) 
		father[a] = b;
	else
		father[b] = a, rank[a]++;
}
int main( )
{
	int p,q,count,j,c;
	j=1;
	while( scanf("%d%d",&p,&q) && !( p==-1 && q==-1 ) )
	{
		if( p==0 && q==0 )
			printf("Case %d is a tree.\n",j );	
		else 
		{
			memset( visit, false, sizeof(visit) );
			inti_set( );
			num=0;  count=0;  c=0; 
			do
			{
				c++;
				if( !visit[p] )count++;
				if( !visit[q] )count++;
				visit[p]=visit[q]=true;
				union_set( p, q );
			}while( scanf("%d%d",&p,&q) && !( p==0 && q==0 ) );
			if( num==0 && count==0 || num+1==count && num==c )
				printf("Case %d is a tree.\n",j );
			else printf("Case %d is not a tree.\n",j );
		}
		j++;
	}
	return 0;
}



//#include<iostream>
//using namespace std;
//#define MAXN 50001
//class Set
//{
//	int set[MAXN],rank[MAXN];
//	bool vis[MAXN];
//public:
//	Set( )
//	{
//		int i;
//		for ( i=0 ; i<MAXN ; i++ )
//			set[i]=i,rank[i]=0,vis[i]=false;
//	}
//	int Find( int v )
//	{
//		if ( set[v]==v )
//			return v;
//		return set[v]=Find(set[v]);
//	}
//	void Union ( int x, int y )
//	{
//		if ( rank[x]>rank[y] )
//			set[Find(y)]=Find(x);
//		else
//			if ( rank[x]<rank[y] )
//				set[Find(x)]=Find(y);
//			else
//			{
//				set[Find(x)]=Find(y);
//				rank[y]++;
//			}
//	}
//	bool judge ( int n )
//	{
//		int res=0;
//		for ( int i=1 ; i<=n ; i++) 
//			if ( !vis[Find(i)] )
//			{
//				vis[Find(i)]=true,res++;
//				if ( res>1 )
//					return false;
//			}
//		return true;
//	}
//};
//int map[MAXN],n;
//int add( int x )
//{
//	return map[x]==-1?map[x]=++n:map[x];
//}
//int main ( )
//{
//	int i,x,y,m,res,cnt=1;
//	bool flag;
//	while ( scanf("%d%d",&x,&y)!=EOF )
//	{
//		if ( x==-1 && y==-1 )
//			break;
//		if ( x==0 && y==0 )
//		{
//			printf("Case %d is a tree.\n",cnt++);
//			continue;
//		}
//		Set set;
//		flag=true;
//		memset(map,-1,sizeof(map));
//		n=0;
//		x=add(x);
//		y=add(y);
//		if ( x!=y )
//			set.Union(x,y);
//		else
//			flag=false;
//		while ( scanf("%d%d",&x,&y) )
//		{
//			if ( x==0 && y==0 )
//				break;
//			x=add(x);
//			y=add(y);
//			if ( flag )
//			{
//				if ( set.Find(x)==set.Find(y) )
//					flag=false;
//				else
//					set.Union(x,y);
//			}
//		}
//		if ( flag )
//			flag=set.judge(n);
//		flag==true?printf("Case %d is a tree.\n",cnt++):printf("Case %d is not a tree.\n",cnt++);
//	}
//}