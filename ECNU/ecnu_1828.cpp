#include<iostream>
using namespace std;
int main( )
{
	int t,h,m,s;
	while( scanf("%d",&t) && t!=-1 )
	{
		h=t/3600;
		t=t%3600;
		m=t/60;
		s=t%60;
		printf("%.2d:%.2d:%.2d\n",h,m,s);
	}
	return 0;
}