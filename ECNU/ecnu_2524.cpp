// ��Ŀ������nͷ��ţ������������˵��������ÿͷ��ţ��Ҫ���ѵ�ʱ�䣬Ȼ�����P��·��ϡ��ͼ����
// ��Ҫ���ѵ�ʱ�䣬��Ҫ������ȥ�������ܶ��·������Ҫ��֤ͼ����ͨ�ԣ����������ĳ����㣬
// �����չ���ÿͷţ��ص������Ҫ���ѵ�����ʱ�䣬ÿ·��һͷ��ţ��Ҫ����˵����
// Ҳ����˵ÿͷţ����Ҫ����˵��λ����ؼ�����ΰ���������С��������ϵ������
// ���뵽������չ·������·�ĳ��ȼ��Ϻ���ţ���൱���㣩˵����ʱ�䡣
// ��ȷ���ǿ���֤���ģ����ȣ�Ҫȥ�������ܶ�ĵ㣬����������µı�Ȼ�ǿ������������л���
// ����һ��������ĳ�㣨�Ըõ�Ϊ�����������������ԵĽ���Ժ�ص�����㣬ÿ���߱�Ȼ��Ҫ�����飬
// ����һ���������ӵĽ���϶�����һ��ͣ��������ţ˵������
// ���Խ�ͼ��ʱ��ֻҪ�ѱߵ�Ȩֵ����ԭ����Ȩֵ����2���ϱ����ӵ���������ֵ��
// ����һ����С�������Ϳ����ˣ�ע�⻹Ҫ���ϸ��ڵ��ֵ����Ϊһ������ʱ�������ڸ��ϣ�
// ��һ���Ƕ������,���ڸ�������ģ�����ȡ��С�ġ�������ϡ��ͼ����Kruskal+���鼯�ȽϷ��㡣


#include<iostream>
#include<algorithm>
#define MAXN 100002
#define INF 999999999
using namespace std;
struct edge
{
	int x,y;
	int val;
	bool operator<( const edge &b )
	{
		return val<b.val;
	}
};
edge e[MAXN];
int father[MAXN],rank[MAXN];
int a[10002];
void init_set( int n )
{
	int i=0;
	for( i=0; i<n; i++ )
	{
		father[i]=i;
		rank[i]=1;
	}
}

int find_root( int x )
{
	if( father[x]!=x )
		father[x]=find_root( father[x] );
	return father[x];
}

void union_set( int p, int q )
{
	int a,b;
	a = find_root(p);
	b = find_root(q);
	if( rank[a] > rank[b] )
		father[b] = a;
	else if( rank[a] < rank[b] ) 
		father[a]=b;
	else
		father[b]=a, rank[a]++;
}

int main( )
{
	int i,j,n,m,x,y,val,min;
	scanf("%d%d",&n,&m);
	min=INF;
	for( i=1; i<=n; i++ )
	{
		scanf("%d",&a[i]);
		if( a[i]<min )min=a[i];
	}
	for( i=0; i<m; i++ )
	{
		scanf("%d%d%d",&x,&y,&val);
		e[i].x=x,e[i].y=y;
		e[i].val=val*2+a[x]+a[y];
	}
	sort( e, e+m );
	init_set( n );
	for( i=0, j=n-1; i<m && j; i++ )
	{
		x=find_root( e[i].x );
		y=find_root( e[i].y );
		if( x!=y )
		{
			union_set( e[i].x, e[i].y );
			min+=e[i].val;
			j--;
		}
	}
	printf("%d\n",min);
	return 0;
}