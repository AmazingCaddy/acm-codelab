#include<stdio.h>
#define pi 3.14159265358979323846
int main()
{
	int t,a,b,c,r,h;
	double v1,v2;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d%d",&a,&b,&c,&r,&h);
		v1=a*b*c;
		v2=pi*r*r*h;
		if(v1-v2>1e-3)printf("%.2f\n",v2);
		else printf("%.2f\n",v1);
	}
	return 0;
}