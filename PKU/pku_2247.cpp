//  һ��humble����{2��3��5��7}�Ļ�һ����һ��humble����ô�ҳ�����������С����Ϊ�µ�humble��
//  Ϊ�˼ӿ��������̣�����ʹ��һ����������С�������¼���������
//  ĳ��humble�Ļ�<=��ǰ���humble������λ�ã��������Թ��˵�С������
//  �����������humble��λ�õ���һ��������������ĳ˻�������������ܲ�����
//  ��С��δ���ɵ�humble���Ƚ�ÿ�������ܲ�������С��humble��ѡһ����С����Ϊ�µ�humble

#include <iostream>
using namespace std;
int cnt=1;
int p[4]={2,3,5,7};
const int INF=2000000000;

int main( )
{
	int num[5842]={1};
	int a[4]={0};
	int prime[4]={2,3,5,7};
	int min;
	int count=0; 
	int i,n;    
	for(count=1;count<5842;count++)
	{
		for(i=0;i<4;i++)
		{
			if(num[a[i]]*prime[i]<=num[count-1])
				a[i]++;
		}
		min=2000000001;
		for(i=0;i<4;i++)
		{
			if(prime[i]*num[a[i]]<min)
			{
				min=prime[i]*num[a[i]];                
			}
		}
		num[count]=min;
	}
	while( scanf("%d",&n) && n )
	{
		if(n%10==1&&n%100!=11)
			printf("The %dst humble number is %d.\n",n,num[n-1]);
		else if(n%10==2&&n%100!=12)
			printf("The %dnd humble number is %d.\n",n,num[n-1]);
		else if(n%10==3&&n%100!=13)
			printf("The %drd humble number is %d.\n",n,num[n-1]);
		else
			printf("The %dth humble number is %d.\n",n,num[n-1]);
	}    
}

//#include <algorithm>
//#include <functional>
//#include <iostream>
//#include <vector>
//using namespace std;
//
//const int N=5842;
//const int fac[]={2,3,5,7};
//
//int main()
//{
//	double x,ans[5843];
//	vector<double> heap(1);
//	heap[0]=1;
//	int i,j;
//	for(i=1;i<=N;i++)
//	{
//		x=heap[0],ans[i]=x;
//		pop_heap(heap.begin(),heap.end(),greater<double>());
//		heap.pop_back();
//		for(j=0;j<4;j++)
//		{
//			if(find(heap.begin(),heap.end(),x*fac[j])==heap.end())
//			{
//				heap.push_back(x*fac[j]);
//				push_heap(heap.begin(),heap.end(),greater<double>());
//			}
//		}
//	}
//	while(scanf("%d",&j),j)
//	{
//		printf("The %d%s humble number is %.0lf.\n",j,j%100>10 && j%100<=20 ? "th" : (j%10==1 ? "st" : (j%10==2 ? "nd" : (j%10==3 ? "rd" : "th"))),ans[j]);
//	}
//	return 0;
//}