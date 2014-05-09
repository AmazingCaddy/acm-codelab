//  该题题意是为了求出能够覆盖所有岛屿的最小雷达数目，每个小岛对应x轴上的一个区间，
//  在这个区间内的任何一个点放置雷达，则可以覆盖该小岛，
//  区间范围的计算用[x-sqrt(d*d-y*y),x+sqrt(d*d-y*y)];
//  这样，问题即转化为已知一定数量的区间，求最小数量的点，使得每个区间内斗至少存在一个点。

//  例如这组数据：
//  3 2
//  0 0
//  1 2
//  4 0
//  我们算出区间并按区间起始位置排序后有：[-2，2],[1，1],[2，6]三个区间。
//  我们用一个变量currentRight记录当前的最右的雷达（为了能够照顾到后面的雷达，
//  我们总是尽可能把雷达放置在右端），首先初始化currentRight=range[1].right;
//  因为range[2].right<=currentRight，因此区间1包含区间2，这时候我们不给2增加雷达,
//  而是把currentRight往左移至range[2].right，更新currentRight=1;对于区间3，
//  因为currentRight=1<range[3].left,这时就要增加一个雷达数，
//  然后更新currentRight=range[3].right。
//  还有一种可能是range[i].left<=currentRight<=range[i].right。
//  这时currentRight已经可以覆盖该区间，直接跳过。

#include<iostream>
#include<cmath>
#include<algorithm>
#define MAXN 1002
using namespace std;
struct node
{
	double left,right;
	bool operator<( const node &a )
	{
		return left<a.left;
	}
};
node a[MAXN];

int main( )
{
	int n,i,ans,k;
	bool flag;
	double x,y,currentright,d;
	k=1;
	while( scanf("%d%lf",&n,&d) && !( n==0 && d==0 ) )
	{
		flag=false;
		for( i=0; i<n; i++ )
		{
			scanf("%lf%lf",&x,&y);
			if( fabs(y)>d )flag=true;
			else 
			{
				a[i].left=x-sqrt(d*d-y*y);
				a[i].right=x+sqrt(d*d-y*y);
			}
		}
		if( flag ) printf("Case %d: -1\n",k++);
		else 
		{
			sort( a, a+n );
			ans=1;
			currentright=a[0].right;
			for( i=1; i<n; i++ )
			{
				if( currentright>=a[i].right )currentright=a[i].right;
				else if( a[i].left>currentright )ans++,currentright=a[i].right;
			}
			printf("Case %d: %d\n",k++,ans);
		}
	}
	return 0;
}