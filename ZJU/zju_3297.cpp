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
//			while( amount[j]>=r[j].min && j<=k ) j++;//�����Ƿ�ȫ������=>min
//			if( j == k+1 )
//			{
//				for( ; ; )
//				{
//					x=f[head];//ȫ�����ڸ��Ե�min�� ��ͷ��ʼ���ɾȥ ��ȫ=>min��ԭ��
//					if(amount[x]-1>=r[x].min)
//					{
//						amount[x]--;//��ɾ��ɾ
//						head++;
//					}
//					else//���ɾ�˻� �ƻ�ȫ>min��ԭ��ͼ���Ƿ�ȫ<=max
//					{
//						for(m=1;m<=k;m++) if(amount[m]>r[m].max) break;
//						if(m==k+1)
//						{
//							if(ans>tail-head) ans=tail-head;//����ȫ<=max����ans�Ƚ�
//						}
//						amount[x]--;//�����������㶼��ͷɾȥ
//						head++;
//						j=x;//�ü������ ��Ȼ������>=min �����Ǳ�ɾȥ��ֵ�� ����ѭ�� ֱ��x��ֵ�ĸ����ٴ�����>=min
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