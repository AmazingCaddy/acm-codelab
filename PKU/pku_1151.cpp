#include<iostream>
#include<algorithm>
#define MAXN 205
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
	double len;
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
point Xpoint[MAXN],Ypoint[MAXN];
line yline[MAXN];
int Xpost[MAXN][2],Ypost[MAXN][2];

void make_tree( int v, int l, int r )
{
	int mid;
	tree[v].L=l;
	tree[v].R=r;
	tree[v].len=0;
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
	if( tree[v].cover>0 )                       //整条线段被覆盖
		tree[v].len=Ypoint[tree[v].R].y-Ypoint[tree[v].L].y;
	else if( tree[v].R-tree[v].L==1 )    		//未被完全覆盖，且是叶节点
		tree[v].len=0;
	else tree[v].len=tree[v<<1].len+tree[(v<<1)+1].len;  
	//未被完全覆盖，但是内部节点
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
	else if( mid<=l ) update( (v<<1)+1, l, r, flag );
	else 
	{
		update( v<<1, l, mid, flag );
		update( (v<<1)+1, mid, r, flag );
	}
	getlen( v );
}

int main( )
{
	int n,i,t1,t2,cas=0;
	double x1,x2,y1,y2;
	while( scanf("%d",&n) && n )
	{
		for( i=0; i<n; i++ )
		{
			scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
			t1=i<<1;t2=(i<<1)+1;
			yline[t1].x=x1,yline[t2].x=x2;
			yline[t1].flag=1;yline[t2].flag=-1;
			Ypoint[t1].y=y1;Ypoint[t2].y=y2;
			Ypoint[t1].num=-(i+1);Ypoint[t2].num=i+1;
			Xpoint[t1].y=x1;Xpoint[t2].y=x2;
			Xpoint[t1].num=-(i+1);Xpoint[t2].num=i+1;
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
			    //下端坐标
			else Ypost[Xpost[Ypoint[i].num-1][0]][1]=Ypost[Xpost[Ypoint[i].num-1][1]][1]=i;
			    //上端坐标
		}
		make_tree( 1, 0, (n<<1)-1 );
		double ans=0;
		update( 1, Ypost[0][0], Ypost[0][1], yline[0].flag );
		for( i=1; i<(n<<1); i++ )
		{
			ans+=tree[1].len*( yline[i].x-yline[i-1].x);
			update( 1, Ypost[i][0], Ypost[i][1], yline[i].flag );
		}
		printf("Test case #%d\nTotal explored area: %.2lf\n\n",++cas,ans);
	}
	return 0;
}



//#include <iostream>
//#include <algorithm>
//#define maxn 10
////#define l(x) x<<1
////#define r(x) (x<<1)+1
//using namespace std;
//int i,j,t,cas=0;
//double ans,x1,x2,y1,y2,y[maxn<<1];
//struct segment_tree
//{
//	double l,r,len;
//	int cover;
//};
//segment_tree tree[maxn<<1];
//struct line
//{
//	bool operator <(const line& a)const
//	{
//		return x<a.x;
//	}
//	double x,y1,y2;
//	int flag;
//};
//
//line mem[maxn<<1];
//void lens(int node)
//{
//	if(tree[node].cover>0)tree[node].len=tree[node].r-tree[node].l;
//	else tree[node].len=tree[node<<1].len+tree[(node<<1)+1].len;
//}
//
//void build(int node,int l,int r)
//{
//	tree[node].l=y[l];
//	tree[node].r=y[r];
//	tree[node].cover=0;
//	tree[node].len=0;
//	if(r==(l+1))return;
//	int mid=(l+r)>>1;
//	build(node<<1,l,mid);
//	build((node<<1)+1,mid,r);
//}
//
//void update(int node,line t)
//{
//	if(tree[node].l==t.y1&&tree[node].r==t.y2)
//	{
//		tree[node].cover+=t.flag;
//		lens(node);
//		return ;
//	}
//	if(tree[node<<1].r<=t.y1)update((node<<1)+1,t);
//	else if(tree[(node<<1)+1].l>=t.y2)update(node<<1,t);
//	else
//	{
//		line t1=t;
//		t1.y2=tree[node<<1].r;
//		update(node<<1,t1);
//		t1=t;
//		t1.y1=tree[(node<<1)+1].l;
//		update((node<<1)+1,t1);
//	}
//	lens(node);
//}
//int main( )
//{
//	while(scanf("%d",&t)!=EOF&&t)
//	{
//		ans=0;
//		for(i=j=0;i<t;i++)
//		{
//			scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
//			mem[j].x=x1;
//			mem[j].y1=y1;
//			mem[j].y2=y2;
//			mem[j].flag=1;
//			y[j]=y1;
//			mem[j+1].x=x2;
//			mem[j+1].y1=y1;
//			mem[j+1].y2=y2;
//			mem[j+1].flag=-1;
//			y[j+1]=y2;
//			j+=2;
//		}
//		sort(y,y+j);
//		sort(mem,mem+j);
//		build(1,0,j-1);
//		update(1,mem[0]);
//		for(i=1;i<j;i++)
//		{
//			ans+=tree[1].len*(mem[i].x-mem[i-1].x);
//			update(1,mem[i]);
//		}
//		printf("Test case #%d\nTotal explored area: %.2lf\n\n",++cas,ans);
//	}
//}

////离散化 + 线段树 + 扫描线
////本题与poj 1177 picture 极相似,现在回想起来甚至比 1177 还要简单一些.
////与 1177 不同的是本题中的坐标是浮点
////类型的故不能将坐标直接离散.我们必须为它们建立一个对应关系,用一个整数去对应一个浮点数
////这样的对应关系在本题的数组 y[] 中 
//#include<iostream>
//#include<algorithm>
//#include<cmath>
//#include<iomanip>
//using namespace std;
//
//struct node
//{
//	int st, ed, c;   //c : 区间被覆盖的层数, m: 区间的测度 
//	double m;
//}ST[802];
//struct line
//{
//	double x,y1,y2;   //纵方向直线, x:直线横坐标, y1 y2:直线上的下面与上面的两个纵坐标 
//	bool s;     //s = 1 : 直线为矩形的左边, s = 0:直线为矩形的右边 
//}Line[205];
//double y[205],ty[205]; //y[] 整数与浮点数的对应数组; ty[]:用来求y[]的辅助数组
//
//void build(int root, int st, int ed)
//{
//	ST[root].st = st;
//	ST[root].ed = ed;
//	ST[root].c = 0;
//	ST[root].m = 0;
//	if(ed - st > 1)
//	{
//		int mid = (st+ed)/2;
//		build(root*2, st, mid);
//		build(root*2+1, mid, ed);
//	}
//}
//inline void updata(int root)
//{
//	if(ST[root].c > 0)
//		//将线段树上区间的端点分别映射到y[]数组所对应的浮点数上,由此计算出测度 
//		ST[root].m = y[ST[root].ed-1] - y[ST[root].st-1];
//	else if(ST[root].ed - ST[root].st == 1)
//		ST[root].m = 0;
//	else ST[root].m = ST[root*2].m + ST[root*2+1].m;
//}
//void insert(int root, int st, int ed)
//{
//	if(st <= ST[root].st && ST[root].ed <= ed)
//	{
//		ST[root].c++;
//		updata(root);
//		return ;
//	}
//	if(ST[root].ed - ST[root].st == 1)return ;//不出错的话这句话就是冗余的 
//	int mid = (ST[root].ed + ST[root].st)/2;
//	if(st < mid)
//		insert(root*2, st, ed);
//	if(ed > mid)
//		insert(root*2+1, st, ed);
//	updata(root);
//}
//void Delete(int root, int st, int ed)
//{
//	if(st <= ST[root].st && ST[root].ed <= ed)
//	{
//		ST[root].c--;
//		updata(root);
//		return ;
//	}
//	if(ST[root].ed - ST[root].st == 1)return ; //不出错的话这句话就是冗余的 
//	int mid = (ST[root].st + ST[root].ed)/2;
//	if(st < mid)
//		Delete(root*2, st, ed);
//	if(ed > mid)
//		Delete(root*2+1, st, ed);
//	updata(root);
//}
//int Correspond(int n, double t)
//{
//	//二分查找出浮点数t 在数组y[]中的位置(此即所谓的映射关系) 
//	int low,high,mid;
//	low = 0; high = n-1;
//	while(low < high)
//	{
//		mid = (low+high)/2;
//		if(t > y[mid])
//			low = mid + 1;
//		else high = mid;
//	}
//	return high+1;
//}
//bool cmp(line l1, line l2)
//{
//	return l1.x < l2.x;
//}
//
//int main()
//{
//	int n,i,num,l,r,c=0;
//	double area,x1,x2,y1,y2;
//	while(cin>>n, n)
//	{
//		for(i = 0; i < n; i++)
//		{
//			cin>>x1>>y1>>x2>>y2;
//			Line[2*i].x = x1;
//			Line[2*i].y1 = y1; 
//			Line[2*i].y2 = y2;
//			Line[2*i].s = 1;
//			Line[2*i+1].x = x2;
//			Line[2*i+1].y1 = y1; 
//			Line[2*i+1].y2 = y2; 
//			Line[2*i+1].s = 0;
//			ty[2*i] = y1; 
//			ty[2*i+1] = y2;
//		}
//		n <<= 1;
//		sort(Line, Line+n, cmp);
//		sort(ty, ty+n);
//		y[0] = ty[0];
//		//处理数组ty[]使之不含重覆元素,得到新的数组存放到数组y[]中 
//		for(i=num=1; i < n; i++)
//			if(ty[i] != ty[i-1])
//				y[num++] = ty[i];
//		build(1, 1, num); //树的叶子节点与数组y[]中的元素个数相同,以便建立一一对应的关系 
//		area = 0;
//		for(i = 0; i < n-1; i++)
//		{
//			//由对应关系计算出线段两端在树中的位置 
//			l = Correspond(num, Line[i].y1);
//			r = Correspond(num, Line[i].y2);
//			if(Line[i].s) //插入矩形的左边 
//				insert(1, l, r);
//			else    //删除矩形的右边 
//				Delete(1, l, r);
//			area += ST[1].m * (Line[i+1].x - Line[i].x);
//		}
//		cout<<"Test case #"<<++c<<endl<<"Total explored area: ";
//		cout<<fixed<<setprecision(2)<<area<<endl<<endl;
//	}
//	return 0;
//}