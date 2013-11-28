////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  
// ���粻��ɢ�������߶������Ͻ���10e7�����罨һ����ô����߶����Ļ���������ȻMLE������Ҫ������ɢ����
// ��ɢ����Ŀ�ľ���Ҫ���߶εĳ����ʵ�����С�������ƻ����⡣                                         
// ���磺                                                                                           
// ------   ��1��6��
// ------------ ��1��12 ��
// �����������������߶Σ����԰����ǿ�����
// -- ��1��2��
// --- �� 1��3 ��
// �������������߶εĳ��ȣ��������ǵĸ��ǹ�ϵ��û�иı䡣
// �ؼ�����Ҫ���¸�ѹ������߶α�������յ㡣
// ����ͨ�õ���ɢ��������������
// �������ζ����߶ζ˵����꣬����post[MAXN][2]�У�post[i][0]���i���߶ε���㣬
// post[i][1]���i���߶ε��յ㣬Ȼ����һ���ṹ������line[MAXN]��¼��Ϣ��
// line[i].li��¼�˵����꣬line[i].num��¼��������ڵڼ����߶�
// ��������������ʾ��������ʾ��㣬������ʾ�յ㡣
// ������N���߶Σ�����2*N���˵㡣Ȼ��line�������򣬰��ն˵�����꣬��С�����š�
// ����Ҫ���߶θ����µĶ˵������ˡ������Ұ��յ����Ĵ������θ��¶˵㣬
// ����2*N�����У�����M����ͬ����ĵ㣬��ô�߶����ķ�Χ����[1,M]��
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
        //��¼�˵�
        for ( i=0 ; i<n ; i++ )
        {
            scanf("%d%d",&post[i][0],&post[i][1]);
            line[i<<1].li=post[i][0];
			line[i<<1].num=-(i+1);           //��ʾ���
			line[(i<<1)+1].li=post[i][1];
			line[(i<<1)+1].num=i+1;          //��ʾ�յ�
        }
        //��ɢ������
        sort( line, line+n*2 );
        int tp=1,temp=line[0].li;
        for( i=0; i<2*n; i++ )
        {
            if( line[i].li!=temp )  
            {
                tp++;
                temp=line[i].li;
            }
            if( line[i].num<0 ) post[-line[i].num-1][0]=tp;    //��ʾ���
            else  post[line[i].num-1][1]=tp;    //��ʾ�յ�
        }
		//������ɢ��֮��ͬ��ĸ���������tp��
        make_tree( 1, 1, tp );
        for ( i=0 ; i<n ; i++ )
            update( 1, post[i][0], post[i][1], i+1 );
        sum(1);
        printf("%d\n",cnt);
    }
}
