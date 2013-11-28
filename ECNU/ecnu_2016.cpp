#include<stdio.h>
int main()
{
	int hp1,hp2,at1,at2,n,m;
	char a1[3],a2[3];
	while(scanf("%d%2s%d",&hp1,a1,&hp2)!=EOF)
	{
		scanf("%d%2s%d",&at1,a2,&at2);
		n=hp1/at2;
		m=hp2/at1;
		if(n>m)printf("1\n");
		else printf("2\n");
	}
	return 0;
}
