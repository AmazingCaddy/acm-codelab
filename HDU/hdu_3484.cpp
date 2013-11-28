#include<iostream>
#include<cstdio>
#include<cstring>
//����ͼ���ƥ��,hungary�㷨,�ڽ�����ʽ,���Ӷ�O(m*m*n)
//�������ƥ����,�������ͼ��Сm,n���ڽ���mat,����Ԫ�ر�ʾ�б�
//match1,match2����һ�����ƥ��,δƥ�䶥��matchֵΪ-1
#include <string.h>
#define MAXN 102
#define _clr(x) memset(x,0xff,sizeof(int)*MAXN)
using namespace std;
int  g1[102][102],g2[102][102];
int mat[102][102],match1[102],match2[102],m,n;
int hungary(int m,int n,int mat[][MAXN],int* match1,int* match2)
{
	int s[MAXN],t[MAXN],p,q,ret=0,i,j,k;
	for (_clr(match1),_clr(match2),i=0;i<m;ret+=(match1[i++]>=0))
		for (_clr(t),s[p=q=0]=i;p<=q&&match1[i]<0;p++)
			for (k=s[p],j=0;j<n&&match1[i]<0;j++)
				if (mat[k][j]&&t[j]<0){
					s[++q]=match2[j],t[j]=k;
					if (s[q]<0)
						for (p=j;p>=0;j=p)
							match2[j]=k=t[j],p=match1[k],match1[k]=j;
				}
				return ret;
}

int ab[102],st[102];
bool cmp( )
{
	int i;
	for(i=0;i<n;i++)if(ab[i]!=st[i])return false;
	return true;
}
int main( )
{
	int i,j,t,u,v,r,s,k;
	while(scanf("%d%d",&n,&m)&&(!(n<0&&m<0)))
	{		
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				scanf("%d",&g1[i][j]);
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				scanf("%d",&g2[i][j]);
		int flag=0;
		for(i=0;i<m;i++)
		{
			memset(mat,0,sizeof(mat));
			for(j=0;j<n;j++)
				ab[j]=g1[j][0]^g2[j][i];
			//mat[0][i]=1;
			for(k=0;k<m;k++)
			{
				s=0;
				for(u=0;u<m;u++)
				{
					for(v=0;v<n;v++)
					{
						st[v]=g1[v][k]^g2[v][u];
					}
					if(cmp()){mat[k][u]=1;s++;}
				}
				if(!s){break;}
			}
			if(!s)continue;
			t=hungary(m,m,mat,match1,match2);
			if(t==m){flag=1;break;}
		}
		if(flag)puts("Yes");
		else puts("No");
	}
	return 0;
}
