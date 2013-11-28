#include<algorithm>
#include<iostream>
#include<stdio.h>
int main()
{
	int m,t,u,f,d,ans=0;
	char c;
	int i;
	bool flag;
	scanf("%d%d%d%d%d",&m,&t,&u,&f,&d);
	for(i=0;i<t;i++)
	{
		flag=0;
		scanf("\n%c",&c);
		if(flag)
			continue;
		if(c=='u'||c=='d')
		{
			m-=u;
			m-=d;
		}
		if(c=='f')
		{
			m=m-2*f;
		}
		if(m>=0)
			ans++; 
		else
			flag=1;

	}
	printf("%d\n",ans);
	return 0;
}