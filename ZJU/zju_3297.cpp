//#include <stdio.h>
//#include <string.h>
//#define N 400010
//#define M 2100
//int f[N];
//int amount[M];
//struct line
//{
//	int min;
//	int max;
//}r[M];
//int main()
//{
//	int x;
//	int n,k,i,j,m;
//	int ans,head,tail;
//	while(scanf("%d%d",&n,&k)!=EOF)
//	{
//		ans=n+1;
//		memset( f, 0, sizeof(f) );
//		memset( r, 0, sizeof(r) );
//		memset( amount, 0, sizeof(amount) );
//		for( i=0; i<n; i++ ) 
//			scanf("%d",&f[i]);
//		for( i=1; i<=k; i++ )
//			scanf("%d%d",&r[i].min,&r[i].max);
//		head=tail=0;
//		for( i=0, j=1; i<n; i++ )
//		{
//			amount[f[i]]++;
//			tail++;
//			while( amount[j]>=r[j].min && j<=k ) j++;//检验是否全部满足=>min
//			if( j == k+1 )
//			{
//				for( ; ; )
//				{
//					x=f[head];//全部大于各自的min后 从头开始逐个删去 按全=>min的原则
//					if(amount[x]-1>=r[x].min)
//					{
//						amount[x]--;//能删就删
//						head++;
//					}
//					else//如果删了会 破坏全>min的原则就检查是否全<=max
//					{
//						for(m=1;m<=k;m++) if(amount[m]>r[m].max) break;
//						if(m==k+1)
//						{
//							if(ans>tail-head) ans=tail-head;//满足全<=max就与ans比较
//						}
//						amount[x]--;//不管满不满足都把头删去
//						head++;
//						j=x;//让检验点在 虽然不满足>=min 但还是被删去的值上 继续循环 直到x的值的个数再次满足>=min
//						break;
//					}
//				}
//			}
//		}
//		if( ans==n+1 ) printf("-1\n");
//		else printf("%d\n",ans);
//	}
//	return 0;
//}