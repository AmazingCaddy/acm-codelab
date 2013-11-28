#include<iostream>
using namespace std;
#define MAXN 30
int dir[8][2]={{-1,-2},{1,-2},{-2,-1},{2,-1},{-2,1},{2,1},{-1,2},{1,2}};//�˸�����
bool visit[MAXN][MAXN];
int x[MAXN],y[MAXN];     //�ֱ��¼x���y������
int m,n;

bool dfs( int p, int q, int step )
{
	int i,newx,newy;
	if( step == m*n )  return true;
	for( i=0; i<8; i++ )
	{
		newy=p+dir[i][0];newx=q+dir[i][1];    
		//y���x������,ע��������˳����Ϊ���·��ʱ
		//����������ֵ����ŵ�·��������A,B...Z��˳������
		if( !visit[newy][newx] && newy>=0 && newy<m && newx>=0 && newx<n )
		{
			visit[newy][newx]=true;                    //���Ϊ�Ѿ����ʹ�
			y[step]=newy;x[step]=newx;                 //��¼·������
			if( dfs( newy, newx, step+1 ) )
				return true;
			visit[newy][newx]=false;
			//���û���ҵ������Ϊû�з��ʹ���ͨ�����·���ܹ��ٴη���
		}
	}
	return false;
}

int main()
{
	int t,i,j;
	scanf("%d",&t);
	for( i=1; i<=t; i++ )
	{
		if( i!=1 ) printf("\n");
		scanf("%d%d",&m,&n);
		printf("Scenario #%d:\n",i);
		memset(visit,false,sizeof(visit));
		x[0]=0;y[0]=0;
		visit[0][0]=true;
		if( !dfs( 0, 0, 1 ) )         //���ȡһ�㿪ʼ������һ��ȡ[0,0]
			printf("impossible");   //û���ҵ�
		else 
			for( j=0; j<m*n; j++ )
				printf("%c%c",x[j]+'A',y[j]+'1');
		printf("\n");
	}
	return 0;
}