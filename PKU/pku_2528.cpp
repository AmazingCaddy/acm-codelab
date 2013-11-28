////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  
// 假如不离散化，那线段树的上界是10e7，假如建一个那么大的线段树的话。。。必然MLE。于是要考虑离散化。
// 离散化的目的就是要将线段的长度适当的缩小，但不破坏题意。                                         
// 比如：                                                                                           
// ------   （1，6）
// ------------ （1，12 ）
// 像这样这样的两条线段，可以把它们看作：
// -- （1，2）
// --- （ 1，3 ）
// 这样，缩短了线段的长度，但是他们的覆盖关系并没有改变。
// 关键我们要重新给压缩后的线段标记起点和终点。
// 按照通用的离散化方法。。。。
// 首先依次读入线段端点坐标，存于post[MAXN][2]中，post[i][0]存第i条线段的起点，
// post[i][1]存第i条线段的终点，然后用一个结构体数组line[MAXN]记录信息，
// line[i].li记录端点坐标，line[i].num记录这个点属于第几条线段
// 可以用正负数表示，负数表示起点，正数表示终点。
// 假如有N条线段，就有2*N个端点。然后将line数组排序，按照端点的坐标，从小到大排。
// 接着要把线段赋予新的端点坐标了。从左到右按照递增的次序，依次更新端点，
// 假如2*N个点中，共有M个不同坐标的点，那么线段树的范围就是[1,M]。
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN = 20005 ;
struct NODE
{
    int l,r,c;
}tree[MAXN*4];
struct L
{
    int li,num;
    bool operator < ( const L& r ) const 
    {
        return li<r.li;
    };
};
L line[MAXN];
int post[MAXN][2];
bool vis[MAXN];
int cnt;
void make_tree ( int v, int l, int r )
{
	int mid=(l+r)>>1;
	tree[v].c=0,tree[v].l=l,tree[v].r=r;
	if ( l!=r )
	{
		make_tree( v<<1, l, mid );
		make_tree( (v<<1)+1, mid+1, r );
	}
}
void update ( int v, int l, int r, int c )
{
    int mid;
    if ( tree[v].l==l && tree[v].r==r )
    {
        tree[v].c=c;
        return;
    }
	if ( tree[v].c>0 && tree[v].c!=c )
    {
        tree[v<<1].c=tree[v].c;
        tree[(v<<1)+1].c=tree[v].c;
        tree[v].c=0;
    }
    mid=(tree[v].l+tree[v].r)>>1;
    if ( r<=mid )  update( v<<1, l, r, c );
	else if ( l>mid ) update( (v<<1)+1, l, r, c );
	else
	{
		update( v<<1, l, mid, c );
		update( (v<<1)+1, mid+1, r, c );
	}
}

void sum ( int v )
{
    if ( tree[v].c )
    {
        if ( !vis[tree[v].c] )
        {
            vis[tree[v].c]=true;
            cnt++;
        }
        return;
    }
    sum( v<<1 );
    sum( (v<<1)+1 );
}

int main ( )
{
    int n,N,i;
    scanf("%d",&N);
    while ( N-- )
    {
        cnt=0;
        scanf("%d",&n);
        memset( vis, false, sizeof(vis) );
        //记录端点
        for ( i=0 ; i<n ; i++ )
        {
            scanf("%d%d",&post[i][0],&post[i][1]);
            line[i<<1].li=post[i][0];
			line[i<<1].num=-(i+1);           //表示起点
			line[(i<<1)+1].li=post[i][1];
			line[(i<<1)+1].num=i+1;          //表示终点
        }
        //离散化坐标
        sort( line, line+n*2 );
        int tp=1,temp=line[0].li;
        for( i=0; i<2*n; i++ )
        {
            if( line[i].li!=temp )  
            {
                tp++;
                temp=line[i].li;
            }
            if( line[i].num<0 ) post[-line[i].num-1][0]=tp;    //表示起点
            else  post[line[i].num-1][1]=tp;    //表示终点
        }
		//计算离散化之后不同点的个数，存在tp中
        make_tree( 1, 1, tp );
        for ( i=0 ; i<n ; i++ )
            update( 1, post[i][0], post[i][1], i+1 );
        sum(1);
        printf("%d\n",cnt);
    }
}
