//���Թ���һ��ĸ����F(x)=(1+x+x^2+...+x^n)(1+x^2+x^4+...+x^n)...(1+x^n)��
//�����ĸ����չ�������ÿһ��x^kǰ���ϵ��Ck�����Ƕ�Ӧ������K�ж����ֲ�ֵ���ʽ��

#include <iostream>
using namespace std;
const int MAXN = 105;
int c1[MAXN],c2[MAXN];

int main( )
{
	int i,j,k,n;
	for( i=0; i<=MAXN; i++ )
		c1[i]=1,c2[i]=0;
	for( i=2; i<=MAXN; i++ )
	{
		for( j=0; j<=MAXN; j++ )            
			for( k=0; k+j<=MAXN; k+=i )  //���صĶ���ʽ�˷�
				c2[j+k]+=c1[j];
		for( j=0; j<=MAXN; j++ )
			c1[j]=c2[j],c2[j]=0;
	}
	while(cin>>n) cout<<c1[n]<<endl;
	return 0;
}