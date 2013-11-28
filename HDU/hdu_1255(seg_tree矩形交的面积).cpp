// ����������ҵ����ڵ�ǰ�߷�Χ�Ľڵ㣬cover+=flag��flag�Ǹ���־����ʾ�ǲ���߻�ɾ���ߡ�
// ���²����Ƚϸ��ӡ�
// ��ǰ�ڵ㱻�������λ����ϣ���ô�õ��once��moreֵ���ǽڵ��ʾ�ĳ��ȡ�
// ��ǰ�ڵ㱻����һ�Σ���ôonce���ڽڵ�ĳ��ȣ���more������������������һ�����ϵĳ��ȵĺ͡�
// ���ڵ�û�б����ǣ���ôonce��������������onceֵ�ĺͣ�more������������more��ֵ�ĺ͡�

#include<iostream>
#include<algorithm>
#define MAXN 2005
using namespace std;

struct line
{
	double x;
	double y1,y2;
	int flag;
	bool operator<( const line &a )
	{
		return x<a.x;
	}
};

struct segment_tree
{
	int L,R;
	double once,more;    //once��ʾֻ������һ��,more��ʾ�����Ƕ��
	int cover;
};

struct point 
{
	double y;
	int num;
	bool operator<( const point &a )
	{
		return y<a.y;
	}
};
segment_tree tree[MAXN*4];
point Xpoint[MAXN],Ypoint[MAXN];  // Ypoint[MAXN]���ڴ洢Y����
line yline[MAXN];
int Xpost[MAXN][2],Ypost[MAXN][2];

void make_tree( int v, int l, int r )
{
	int mid;
	tree[v].L=l,tree[v].R=r;
	tree[v].once=tree[v].more=0;
	tree[v].cover=0;
	if( r-l>1 )
	{
		mid=( l+r )>>1;
		make_tree( v<<1, l, mid );
		make_tree( (v<<1)+1, mid, r );
	}
}

void getlen( int v )
{
	if( tree[v].cover>1 )
		tree[v].once=tree[v].more=Ypoint[tree[v].R].y-Ypoint[tree[v].L].y;
	else if( tree[v].cover==1 )
	{
		tree[v].once=Ypoint[tree[v].R].y-Ypoint[tree[v].L].y;
		if( tree[v].L+1==tree[v].R )
			tree[v].more=0;
		else tree[v].more=tree[v<<1].once+tree[(v<<1)+1].once;
	}
	else 
	{
		if( tree[v].L+1==tree[v].R )
			tree[v].more=tree[v].once=0;
		else 
		{
			tree[v].more=tree[v<<1].more+tree[(v<<1)+1].more;
			tree[v].once=tree[v<<1].once+tree[(v<<1)+1].once;
		}
	}
}

void update( int v, int l, int r, int flag )
{
	int mid;
	if( tree[v].L==l && tree[v].R==r )
	{
		tree[v].cover+=flag;
		getlen( v );
		return ;
	}
	mid=( tree[v].L+tree[v].R )>>1;
	if( mid>=r ) update( v<<1, l, r, flag );
	else if( mid<=l )update( (v<<1)+1, l, r, flag );
	else 
	{
		update( v<<1, l, mid, flag );
		update( (v<<1)+1, mid, r, flag );
	}
	getlen( v );
}

int main( )
{
	int n,i,t1,t2,cas=0,t;
	double x1,x2,y1,y2;
	scanf("%d",&t);
	while( t-- )
	{
		scanf("%d",&n);
		for( i=0; i<n; i++ )
		{
			scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
			t1=i<<1;t2=(i<<1)+1;
			yline[t1].x=x1,yline[t2].x=x2;
			yline[t1].flag=1;        yline[t2].flag=-1;
			Ypoint[t1].y=y1;         Ypoint[t2].y=y2;
			Ypoint[t1].num=-(i+1);   Ypoint[t2].num=i+1;
			Xpoint[t1].y=x1;         Xpoint[t2].y=x2;
			Xpoint[t1].num=-(i+1);   Xpoint[t2].num=i+1;
		}
		sort( Xpoint, Xpoint+(n<<1) );
		sort( Ypoint, Ypoint+(n<<1) );
		sort( yline, yline+(n<<1) );
		for( i=0; i<(n<<1); i++ )
		{
			if( Xpoint[i].num<0 )Xpost[-Xpoint[i].num-1][0]=i;
			else Xpost[Xpoint[i].num-1][1]=i;
		}
		for( i=0; i<(n<<1); i++ )
		{
			if( Ypoint[i].num<0 )
				Ypost[Xpost[-Ypoint[i].num-1][0]][0]=Ypost[Xpost[-Ypoint[i].num-1][1]][0]=i;
			else Ypost[Xpost[Ypoint[i].num-1][0]][1]=Ypost[Xpost[Ypoint[i].num-1][1]][1]=i;
		}
		make_tree( 1, 0, (n<<1)-1 );
		double ans=0;
		update( 1, Ypost[0][0], Ypost[0][1], yline[0].flag );
		for( i=1; i<(n<<1); i++ )
		{
			ans+=tree[1].more*( yline[i].x-yline[i-1].x);
			update( 1, Ypost[i][0], Ypost[i][1], yline[i].flag );
		}
		printf("%.2lf\n",ans);
	}
	return 0;
}