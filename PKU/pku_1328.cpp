//  ����������Ϊ������ܹ��������е������С�״���Ŀ��ÿ��С����Ӧx���ϵ�һ�����䣬
//  ����������ڵ��κ�һ��������״����Ը��Ǹ�С����
//  ���䷶Χ�ļ�����[x-sqrt(d*d-y*y),x+sqrt(d*d-y*y)];
//  ���������⼴ת��Ϊ��֪һ�����������䣬����С�����ĵ㣬ʹ��ÿ�������ڶ����ٴ���һ���㡣

//  �����������ݣ�
//  3 2
//  0 0
//  1 2
//  4 0
//  ����������䲢��������ʼλ��������У�[-2��2],[1��1],[2��6]�������䡣
//  ������һ������currentRight��¼��ǰ�����ҵ��״Ϊ���ܹ��չ˵�������״
//  �������Ǿ����ܰ��״�������Ҷˣ������ȳ�ʼ��currentRight=range[1].right;
//  ��Ϊrange[2].right<=currentRight���������1��������2����ʱ�����ǲ���2�����״�,
//  ���ǰ�currentRight��������range[2].right������currentRight=1;��������3��
//  ��ΪcurrentRight=1<range[3].left,��ʱ��Ҫ����һ���״�����
//  Ȼ�����currentRight=range[3].right��
//  ����һ�ֿ�����range[i].left<=currentRight<=range[i].right��
//  ��ʱcurrentRight�Ѿ����Ը��Ǹ����䣬ֱ��������

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