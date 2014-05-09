#include<iostream>
#include<algorithm>
#define MAXN 100010
using namespace std;
struct NODE
{
	int l,r;
	int ID,num;// 分别记录第cnt条木板 和 砖块数量
}tree[MAXN*12];
struct Board
{
	int l,r,h,ID;
};
struct Brick
{
	int l,r;
};
Brick bri[MAXN];
Board ban[MAXN];
int x[MAXN*4];
int n,m,len;
long long ans[MAXN];

bool compare( const Board &a, const Board &b )
{
	return a.h<b.h;
}

int find( int n )
{
	int l=0,r=len-1,mid;
	while( l<=r )
	{
		mid=(l+r)>>1;
		if( x[mid]==n )return mid;
		else if( x[mid]<n )l=mid+1;
		else r=mid-1;
	}
}

void make_tree( int v, int l, int r )
{
	int mid;
	tree[v].l=l,tree[v].r=r,tree[v].ID=0,tree[v].num=0;
	if( l+1 != r )
	{
		mid=(l+r)>>1;
		make_tree( v<<1, l, mid );
		make_tree( (v<<1)+1, mid, r );
	}
}

void lisanhua( )
{
	int i,k=len;
	sort( x, x+len );
	len=1;
	for( i=1; i<k; i++ )
		if( x[i] != x[i-1] )x[len++]=x[i];
	for( i=1; i<=n; i++ )
	{
		bri[i].l=find( bri[i].l );
		bri[i].r=find( bri[i].r );
	}
	for( i=1; i<=m; i++ )
	{
		ban[i].l=find( ban[i].l );
		ban[i].r=find( ban[i].r );
	}
}

void insertboard( int v, int l, int r, int ID )
{
	int mid;
	if( tree[v].l==l && tree[v].r==r )
	{
		tree[v].ID=ID;
		return ;
	}
	if( tree[v].ID )
	{
		if( tree[v].l+1 != tree[v].r )
		{
			tree[v<<1].ID=tree[v].ID;
		    tree[(v<<1)+1].ID=tree[v].ID;
		    tree[v].ID=0;
		}
	}
 	mid=(tree[v].l+tree[v].r)>>1;
	if( r<=mid )insertboard( v<<1, l, r, ID );
	else if( l>=mid )insertboard( (v<<1)+1, l, r, ID );
	else
	{
		insertboard( v<<1, l, mid, ID );
		insertboard( (v<<1)+1, mid, r, ID );
	}
}

void insertbrick( int v, int l, int r )
{
	int mid;
	if( tree[v].l==l && tree[v].r==r )
	{
		tree[v].num++;
		//if( tree[v].l+1==tree[v].r )return ;
		//tree[v<<1].num+=tree[v].num;
		//tree[(v<<1)+1].num+=tree[v].num;
		//tree[v].num=0;
		return ;
	}
	mid=(tree[v].l+tree[v].r)>>1;
	if( r<=mid )insertbrick( v<<1, l, r );
	else if( l>=mid )insertbrick( (v<<1)+1, l, r );
	else 
	{
		insertbrick( v<<1, l, mid );
		insertbrick( (v<<1)+1, mid, r );
	}
}

void query( int v, int l, int r )
{
	int mid;
	if( tree[v].l+1==tree[v].r )
	{
		ans[tree[v].ID]=ans[tree[v].ID]+(long long)(x[tree[v].r]-x[tree[v].l])*(long long)tree[v].num;
		return ;
	}
	if( tree[v].ID )
	{
		tree[v<<1].ID=tree[v].ID;
		tree[(v<<1)+1].ID=tree[v].ID;
		tree[v].ID=0;
	}
	if( tree[v].num )
	{
		tree[v<<1].num+=tree[v].num;
		tree[(v<<1)+1].num+=tree[v].num;
		tree[v].num=0;
	}
	mid=(tree[v].l+tree[v].r)>>1;
	if( r<=mid )query( v<<1, l, r );
	else if( l>=mid ) query( (v<<1)+1, l, r );
	else 
	{
		query( v<<1, l, mid );
		query( (v<<1)+1, mid, r );
	}
}

void solve( )
{
	int i;
	sort( ban+1, ban+m+1, compare ); 
	make_tree( 1, 0, len-1 );
	for( i=1; i<=m; i++ )
		insertboard( 1, ban[i].l, ban[i].r, ban[i].ID );
	for( i=1; i<=n; i++ )
		insertbrick( 1, bri[i].l, bri[i].r );
	memset( ans, 0, sizeof(ans) );
	query( 1, 0, len-1 );
	for( i=1; i<=m; i++ )
		printf("%lld\n",ans[i]);
	printf("\n");
}

int main( )
{
	int i;
	while( scanf("%d%d",&n,&m) != EOF )
	{
		len=0;                         
		for( i=1; i<=n; i++ )
		{
			scanf("%d%d",&bri[i].l,&bri[i].r);
			x[len++]=bri[i].l;
			x[len++]=bri[i].r;
		} 
		for( i=1; i<=m; i++ )
		{
			scanf("%d%d%d",&ban[i].l,&ban[i].r,&ban[i].h);
			x[len++]=ban[i].l;
			x[len++]=ban[i].r;
			ban[i].ID=i;            
		}
		lisanhua( ); 
		solve( );       
	}
	return 0;
}


//#include<iostream>
//using namespace std;
////线段树 
////从天上掉下来一些货物，会被板挡住，在相同高度上，没有板是相互重叠的 
////首先将board从低到高排序，然后插入，对区间贴标签
////然后把brick插入，在插入过程中，不断把值传递给孩子
////最后统计的是叶子的情况 
//int n,m;//n块砖，m块木板
//const int maxn=120000;
//typedef struct brick
//{
//	int l,r;    
//}brick;
//brick b[maxn];
//typedef struct board
//{
//	int l,r,h,id;   
//}board;
//board d[maxn];
//int x[4*maxn],len;
//bool cmp(board x1,board x2)
//{
//	return x1.h<x2.h; 
//}   
//inline int find(int key)
//{
//	int left=0,right=len-1,mid;
//	while(left<=right)
//	{
//		mid=(left+right)>>1;
//		if(x[mid]==key)return mid+1;
//		else if(x[mid]>key)right=mid-1;
//		else left=mid+1;            
//	}   
//}
//void lisanhua()
//{
//	int i,j,k=len;
//	sort(x,x+len);
//	len=1;
//	for(i=1;i<k;i++)if(x[i]!=x[i-1])x[len++]=x[i];
//	//    cout<<"len="<<len<<endl;
//	for(i=1;i<=n;i++)
//	{
//		b[i].l=find(b[i].l);
//		b[i].r=find(b[i].r);
//	//    cout<<"l="<<b[i].l<<" r="<<b[i].r<<endl;          
//	} 
//	for(i=1;i<=m;i++)
//	{
//		d[i].l=find(d[i].l);
//		d[i].r=find(d[i].r);
//	//       cout<<"l="<<d[i].l<<" r="<<d[i].r<<endl;              
//	}       
//}
//
//typedef struct node
//{
//	int l,r,cnt,num;    
//}node;
//node tree[12*maxn];
//long long ans[maxn];        
//void build(int k,int l,int r)
//{
//	//    cout<<"l="<<l<<" r="<<r<<endl;system("pause"); 
//	tree[k].l=l;tree[k].r=r;tree[k].cnt=0;tree[k].num=0;
//	if(r-l==1)return ;
//	int mid=(l+r)>>1;
//	build(k*2,l,mid);
//	build(k*2+1,mid,r); 
//}
//void down(int k)
//{
//	if(tree[k].cnt)
//	{
//		tree[k*2].cnt=tree[k*2+1].cnt=tree[k].cnt;
//		tree[k].cnt=0;            
//	} 
//	if(tree[k].num)
//	{
//		tree[k*2].num+=tree[k].num;
//		tree[k*2+1].num+=tree[k].num;
//		tree[k].num=0;            
//	}   
//}    
//void insertboard(int k,int l,int r,int id)
//{
//	if(r<=tree[k].l||l>=tree[k].r)return;
//	if(l<=tree[k].l&&tree[k].r<=r){tree[k].cnt=id;return;}
//	if(tree[k].r-tree[k].l==1)return ;
//	down(k);
//	insertboard(k*2,l,r,id);    
//	insertboard(k*2+1,l,r,id);
//}
//void insertbrick(int k,int l,int r)
//{
//	if(r<=tree[k].l||l>=tree[k].r)return;
//	if(l<=tree[k].l&&tree[k].r<=r){tree[k].num++;return;}
//	if(tree[k].r-tree[k].l==1)return ;
//	down(k);
//	insertbrick(k*2,l,r);
//	insertbrick(k*2+1,l,r);
//}    
//void query(int k)
//{
//	if(tree[k].r-tree[k].l==1)
//	{
//		ans[tree[k].cnt]+=(long long)(x[tree[k].r-1]-x[tree[k].l-1])*(long long)(tree[k].num);
//		return ;                       
//	}
//	down(k);    
//	query(k*2);
//	query(k*2+1);   
//}    
//void slove()
//{
//	int i,j,k; 
//	sort(d+1,d+m+1,cmp);
//	build(1,1,len);
//	for(i=1;i<=m;i++)insertboard(1,d[i].l,d[i].r,d[i].id);
//	for(i=1;i<=n;i++)insertbrick(1,b[i].l,b[i].r);
//
//	for(i=1;i<=m;i++)ans[i]=0;
//	query(1);
//	for(i=1;i<=m;i++)printf("%lld\n",ans[i]);
//	printf("\n"); 
//}        
//int main()
//{
//	int i,j,k;
//	while(scanf("%d%d",&n,&m)!=EOF)
//	{
//		len=0;                         
//		for(i=1;i<=n;i++)
//		{
//			scanf("%d%d",&b[i].l,&b[i].r);
//			x[len++]=b[i].l;
//			x[len++]=b[i].r;
//		} 
//		for(i=1;i<=m;i++)
//		{
//			scanf("%d%d%d",&d[i].l,&d[i].r,&d[i].h);
//			x[len++]=d[i].l;
//			x[len++]=d[i].r;
//			d[i].id=i;            
//		}
//		lisanhua(); 
//		slove();       
//	}
//	return 0;
//}
