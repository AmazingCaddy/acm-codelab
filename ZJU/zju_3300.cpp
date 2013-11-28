//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#define N 20
//#define M 13
//#define MM 9
//int a[N];
//int b[N];
//int c[N];
//int ans[N];
//int v[N];
//int top;
//int main()
//{
//	int i,j,k,m;
//	int f(const void* a,const void* b);
//	while(scanf("%d",&m)!=EOF)
//	{
//		top=-1;
//		memset(ans,0,sizeof(ans));
//		memset(v,0,sizeof(v));
//		memset(a,0,sizeof(a));
//		a[m]++;
//		for(i=1;i<M;i++)
//		{
//			scanf("%d",&m);
//			a[m]++;
//		}
//		for(i=1;i<=MM;i++)
//		{
//			memset(b,0,sizeof(b));
//			memset(c,0,sizeof(c));
//			for(j=1;j<=MM;j++) c[j]=b[j]=a[j];
//			b[i]++;
//			c[i]++;
//			for(j=1;j<=MM;j++)
//			{
//				if(b[j]>=2)
//				{
//					c[j]-=2;
//					for(k=1;k<=MM+1;k++)
//					{
//						if(c[k]>0)
//						{
//							if(c[k]>=3) c[k]-=3;
//							else
//							{
//								c[k]--;
//								c[k+1]--;
//								c[k+2]--;
//							}
//							k--;
//						}
//						else
//						{
//							if(c[k]<0)
//							{
//								memset(c,0,sizeof(c));
//								for(k=1;k<=MM;k++) c[k]=b[k];
//								break;
//							}
//						}
//					}
//					if(k==MM+2)
//					{
//						memset(c,0,sizeof(c));
//						for(k=1;k<=MM;k++) c[k]=b[k];
//						ans[++top]=i;
//					}
//				}
//			}
//		}
//		qsort(ans,top+1,sizeof(int),f);
//		for(i=0;i<=top;i++) if(a[ans[i]]<4)v[ans[i]]=1;
//		i=0;
//		while(!v[i]) i++;
//		printf("%d",i++);
//		for(;i<=MM;i++) if(v[i]) printf(" %d",i);
//		printf("\n");
//	}
//	return 0;
//}
//
//int f(const void* a,const void* b)
//{
//	return *(int*)a-*(int*)b;
//}
