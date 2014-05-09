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
					temp=opt[j],pre[i]=j;        //temp用于找出i之前符合要求最长的数列的长度
			if ( pre[i]==-1 )
				opt[i]=1;            //如果pre[i]依旧为-1，说明不能从第j个数列推过来
			else
				opt[i]=temp+1;       //否则加上本身一个长度1
			res=max(res,opt[i]);     //将当前的结果与之前的求出的最大结果比较，存下最大的
		}
		cout<<res<<endl;
	}
}
