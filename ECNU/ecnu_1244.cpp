// 设定F[i,j,k]表示放置第i个积木时，把它放在第j堆，用第k种方式放置的总最大高度。
// F[i,j,k]=Max{ F[a,j,b]|(i,k)能放置在(a,b)上, F[a,j-1,b] (0<=a<=i-1,0<=b<=2) } + height(i,k)
// height(i,k)为第i个积木以方式k放置的高。
// F[i,j,k]=负无穷大;(0<=i<=N,0<=j<=M,0<=k<=2)
// F[0,0,0]=0;
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
using namespace std;
const int MAX=101,INF=0x7FFFFFFF;
struct block{int a,b,c;}B[MAX];
int F[MAX][MAX][3];
int N,M,Ans;
void init()
{
	int i,j,k;
	scanf("%d%d",&N,&M);
	for (i=1;i<=N;i++)
		scanf("%d%d%d",&B[i].a,&B[i].b,&B[i].c);
	for (i=0;i<=N;i++)
		for (j=0;j<=M;j++)
			for (k=0;k<3;k++)
				F[i][j][k]=-INF;
	F[0][0][0]=0;
}
 
inline block roll(block A,int k)
{
	int t;
	if (k==1){t=A.b;A.b=A.c;A.c=t;}
	if (k==2){t=A.a;A.a=A.b;A.b=A.c;A.c=t;}
	return A;
}
 
inline bool available(block A,int k1,block B,int k2)
{
	A=roll(A,k1);B=roll(B,k2);
	return (B.a>=A.a && B.b>=A.b) || (B.a>=A.b && B.b>=A.a);
}
 
void dynamic()
{
	int i,j,k,a,b;
	block T;
	for (i=1;i<=N;i++)
		for (j=1;j<=M;j++)
			for (k=0;k<3;k++)
			{
				for (a=0;a<i;a++)
					for (b=0;b<3;b++)
					{
						if (available(B[i],k,B[a],b) && F[a][j][b] > F[i][j][k])
							F[i][j][k] = F[a][j][b];
						if ( F[a][j-1][b] > F[i][j][k] )
							F[i][j][k] = F[a][j-1][b];
					}
				if ((F[i][j][k] += (T=roll(B[i],k)).c) >Ans)
					Ans=F[i][j][k];
			}
}
 
int main()
{
	init();
	dynamic();
	printf("%d\n",Ans);
	return 0;
}
