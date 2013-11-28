#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define MAX 99999999
using namespace std;
int g[105][105];
int th[105][3];
int st[105][105][3];
int main()
{
	int i,j,t,m,n,u,v,r,s,di,k,a,b,sum;
	while(scanf("%d%d",&n,&di)!=EOF)
	{
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				g[i][j]=MAX;
		for(i=0;i<n;i++)
		{
			scanf("%d%d%d",&th[i][0],&th[i][1],&th[i][2]);
			//if(th[i][1]<th[i][0])th[i][1]=th[i][0];
			//if(th[i][2]<th[i][0])th[i][2]=th[i][1];
			scanf("%d",&m);
			while(m--)
			{
				scanf("%d%d",&a,&b);
				g[i][a]=b;
			}
		}
		if(di<=1)
		{
			cout<<0<<endl;
			continue;
		}
		for(k=0;k<n;k++)
			for(i=0;i<n;i++)
				for(j=0;j<n;j++)
					if(g[i][j]>g[i][k]+g[k][j])
						g[i][j]=g[i][k]+g[k][j];
		m=di-1;
		for(i=0;i<=m;i++)
			for(j=0;j<n;j++)
				st[i][j][0]=st[i][j][1]=st[i][j][2]=-MAX;
		st[1][0][0]=th[0][0];
		for(i=1;i<m;i++)
			for(j=0;j<n;j++)
				for(k=0;k<n;k++)
				{
					if(k==j)
					{
						for(r=0;r<3;r++)
						{
							if(st[i][j][r]>=0)
							{
								if(r<2)
								{
									if(st[i+1][k][r+1]<st[i][j][r]+th[j][r+1])
										st[i+1][k][r+1]=st[i][j][r]+th[j][r+1];
								}
								else if(st[i+1][k][2]<st[i][j][2]+th[j][2])st[i+1][k][2]=st[i][j][2]+th[j][2];
							}
						}

					}
					for(r=0;r<3;r++)if(st[i][j][r]>=0)
					{
						if(g[j][k]<MAX&&st[i][j][r]>=g[j][k])
						{
							if(st[i+1][k][0]<st[i][j][r]-g[j][k]+th[k][0])
								st[i+1][k][0]=st[i][j][r]-g[j][k]+th[k][0];
						}
					}
				}
				sum=0;
				for(i=0;i<n;i++)
					for(r=0;r<=2;r++)
						if(sum<st[m][i][r])
							sum=st[m][i][r];
				printf("%d\n",sum);
	}
	return 0;
}
