//���Ӷ�O(2^n*n*2)��״̬ת�Ʒ���:ans[m][i]=ans[m/i][j](j���±�Ϊ0��n-1����a[i]������k����)

#include<iostream> 
#include<cmath>
using namespace std;
const int N=16;
__int64 ans[1<<N][N];

//��һά����һ�����У���2���Ʊ�ʾ���ڶ�ά��ʾ���������һλ���±�

int main( )
{
	int i,j,m,n,k,a[N];
	__int64 res;
	scanf("%d%d",&n,&k);
	for( i=0; i<n; ++i )
		scanf("%d",&a[i]);
	for( i=0; i<n; ++i )
		ans[1<<i][i]=1;
	for( m=0; m<(1<<n); ++m )         //2^n
		for( i=0; i<n; ++i )
			if( m & (1<<i) )            //n^2
				for( j=0; j<n; ++j )
					if( ( m & (1<<j) )==0 && abs(a[i]-a[j])>k )
						ans[m|(1<<j)][j]+=ans[m][i];
	for( res=0, i=0; i<n; ++i )
		res+=ans[(1<<n)-1][i];
	printf("%I64d\n",res);
	return 0;
}