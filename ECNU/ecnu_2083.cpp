#include<iostream>
#define max(m,n) m>n?m:n
using namespace std;
const int MAXN = 100;
int main ( )
{
	int res,temp,j,i,opt[MAXN],arr[MAXN],pre[MAXN],N ;
	while ( cin>>N )
	{
		for ( i=0 ; i<N ; i++  )
			cin>>arr[i];
		opt[0]=1,pre[0]=-1;
		for ( res=i=1 ; i<N ; i++ )
		{
			for ( pre[i]=-1 ,temp=j=0 ; j<i ; j++ )
				if ( (pre[j]==-1 && arr[j]!=arr[i]) || ( pre[j]!=-1 && opt[j]>temp && (arr[j]-arr[pre[j]])*(arr[i]-arr[j])<0) )
					temp=opt[j],pre[i]=j;        //temp�����ҳ�i֮ǰ����Ҫ��������еĳ���
			if ( pre[i]==-1 )
				opt[i]=1;            //���pre[i]����Ϊ-1��˵�����ܴӵ�j�������ƹ���
			else
				opt[i]=temp+1;       //������ϱ���һ������1
			res=max(res,opt[i]);     //����ǰ�Ľ����֮ǰ�������������Ƚϣ���������
		}
		cout<<res<<endl;
	}
}
