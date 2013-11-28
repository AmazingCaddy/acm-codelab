#include<iostream>
#include<queue>
using namespace std;
//  ���˾��ñȽ��鷳��BFS 
//  ���ⱨ�棺��Ŀ��������Щ���ǻ�ﵽ���棬����ﵽ�����˰���������ڽ�4����Ҳ��������
//  ���ȶ�ȡ��ʱ���������������ô����������ǿ�
//  ��״̬ת��ʱҪ�ж�ת��Ŀ����Χ�ĵ��������������������絽��ʱ�䣬����ȵ�ǰ����ô��չ
//  ���һ��Ҳû����Ŀ��㱾��Ҳ���������ǵĸ�����ô������Сֵ��
//  ע�����һ�������ʱ��ȵ�ǰС�Ͳ��ط����� 
int map[401][401];
int a[401][401];
int n,m,sum,num;
struct Node
{
	int x,y,v;    
};
Node s,t;
queue<Node> q;
int dx[4]={ 1, 0, -1, 0 };
int dy[4]={ 0, -1, 0, 1 };
int small( int x, int y )
{
	return x<y?x:y;
}

bool check( int x, int y )
{
	if( x>=0 && x<=400 && y>=0 && y<=400 )return true;
	return false; 
}

void bfs( )
{
	int i,j,x,y,xx,yy,xxx,yyy,min;
	t.x=0,t.y=0,t.v=0;
	q.push( t );
	a[0][0]=0;
	sum=999999999;
	while( !q.empty( ) )
	{
		s=q.front( );
		q.pop( );
		x=s.x;  y=s.y;
		for( i=0; i<4; i++ )
		{
			xx=x+dx[i];     yy=y+dy[i];
			//    ��ͼ�Ϸ���    �õػ��ɸ���ʱ�䣬  ��ͼ��ը������ը������ʱ��Ȱݷõ�ʱ����
			if( check(xx,yy) && a[xx][yy]>s.v+1 && ( map[xx][yy]==-1 || map[xx][yy]>s.v+1+1 ) )
			{ 
				min=999999999; 
				for( j=0; j<4; j++ ) //�ж���һ����������Ƿ�ᱬը 
				{
					xxx=xx+dx[j];    yyy=yy+dy[j];
					if( check( xxx, yyy ) && map[xxx][yyy]!=-1 )
						min=small( min, map[xxx][yyy] );
				}
				if( s.v+1<min )  //min������С�ı�ըʱ�䣬Ҳ���ܲ���ը 
				{
					if( min==999999999 && map[xx][yy]==-1 )  //�˴���Զ������ը��, Ϊ��ȫ�ش�
					{
						if( sum>s.v+1 )//������и��쵽���ʱ�䣬�����֮
							sum=s.v+1;
					}
					else
					{         
						t.x=xx;
						t.y=yy;
						t.v=s.v+1;
						a[xx][yy]=s.v+1;
						q.push(t);
					}
				}
			}
		}
	}
}

int main( )
{
	int i,j,x,y,z;
	scanf("%d",&n);
	for( i=0; i<=400; i++ )
	{
		for( j=0; j<=400; j++ )
		{
			a[i][j]=999999999;
			map[i][j]=-1;   //-1��ʾ�˴�������ը��ը��
		}               
	}
	for( i=0; i<n; i++ )
	{
		scanf("%d%d%d",&x,&y,&z);
		if(map[x][y]==-1)map[x][y]=z;
		else if(map[x][y]>z)map[x][y]=z;//�������絽���Ǹ�ը��ʱ��
	}      
	while( !q.empty( ) )q.pop( );
	bfs( );
	if( sum == 999999999 ) printf("-1\n");
	else printf("%d\n",sum);
	return 0;
}