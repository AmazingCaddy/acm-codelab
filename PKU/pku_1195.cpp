#include<iostream>
#define MAXN 1030
#define lowbit(x) ( x & (-x) )
using namespace std;
int tree[MAXN][MAXN];
void make_tree_array( )
{
	memset( tree, 0, sizeof(tree) );
}

void update( int x, int y, int s, int val )
{
	int temp;
	while( x<=s )
	{
		temp=y;
		while( temp<=s )
		{
			tree[x][temp]+=val;
			temp+=lowbit(temp);
		}
		x+=lowbit(x);
	} 
}

int query( int x, int y )
{
	int sum=0,temp;
	while( x>0 )
	{
		temp=y;
		while( temp>0 )
		{
			sum+=tree[x][temp];
			temp-=lowbit(temp);
		}
		x-=lowbit(x);
	}
	return sum;
}

int main( )
{
	int x1,x2,y1,y2,s,val,m;
	while( scanf("%d",&m) && m!=3 )
	{
		switch (m)
		{
		case 0:
			scanf("%d",&s);
			make_tree_array( );
			break;
		case 1:
			scanf("%d%d%d",&x1,&y1,&val);
			update( x1+1, y1+1, s+1, val );
			break;
		case 2:
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			int temp=query( x2+1, y2+1 )-query( x2+1, y1 )-query( x1, y2+1 )+query( x1, y1 );
			printf("%d\n",temp);
			break;
		}
	}
	return 0;
}
