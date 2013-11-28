// ��������Ϊ���½����л��߲��������У�
// ��������������Ѿ��Ǵ��ڵĲ��½�����len3 ���� ����������len4��ʣ�µľ���Ҫ�޸ĵ�
// ans=n-max{ len3, len4 }
#include<iostream>
#define MAXN 30003
using namespace std;
int a[MAXN],d3[MAXN],d4[MAXN];
int len3,len4;

int search3( int len, int n ) //���½��Ķ��ֺ���
{
	int low=1,high=len,mid;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(n>=d3[mid]) low=mid+1;
		else if(n<d3[mid]) high=mid-1;
	}
	return low;
}

void LNDS( int b[], int n ) //����½�������
{
	int i,t;
	len3=1;
	d3[len3]=a[0];
	for( i=1; i<n; i++ )
	{
		if( a[i]>=d3[len3] )d3[++len3]=a[i];
		else 
		{
			t=search3( len3, a[i] );
			d3[t]=a[i];
		}
	}
}

int search4( int len, int n )//�������Ķ��ֺ���
{
	int low=1,high=len,mid;
	while(low<=high)
	{
		mid=(low+high)/2;
		if( n>d4[mid] ) high=mid-1;
		else if( n<=d4[mid] ) low=mid+1;
	}
	return low;
}

void LNIS( int b[], int n ) //�������������
{
	int i,t;
	len4=1;
	d4[len4]=a[0];
	for( i=1; i<n; i++ )
	{
		if( a[i]<=d4[len4] )d4[++len4]=a[i];
		else 
		{
			t=search4( len4, a[i] );
			d4[t]=a[i];
		}
	}
}

int main( )
{
	int n;
	scanf("%d",&n);
	for( int i=0; i<n; i++ )
		scanf("%d",&a[i]);
	LNIS( d4, n );
	LNDS( d3, n );
	printf("%d\n",n-(len3>len4?len3:len4));
	return 0;
}