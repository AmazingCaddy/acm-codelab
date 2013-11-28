#include<stdio.h>
int main()
{
	int i,j,n;
	__int64 q[45],r[45];     //q数组表示直接的移法，r数组表示隔了一堆的移法
	while(scanf("%d",&n)!=EOF)
	{
		q[0]=0;r[0]=0;
		for(i=1;i<=n;i++)
		{
			q[i]=r[i-1]+1+r[i-1];
			r[i]=r[i-1]+1+q[i-1]+1+r[i-1];
		}
		printf("%I64d\n",q[n]);
	}
	return 0;
}