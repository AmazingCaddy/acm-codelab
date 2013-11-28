#include<iostream>
using namespace std;
int main()
{
	int t,h,m,s;
	scanf("%d",&t);
	while( t-- )
	{
		scanf("%2d:%2d:%2d",&h,&m,&s);
		if( h<7 || h==7 && m<45 || h==7 && m==45 && s==0 )
			printf("You are living a healthy life!\n");
		else if( h==7 && m<50 || h==7 && m==50 && s==0 )
			printf("Hurry up!\n");
		else printf("You are late!\n");
	}
	return 0;
}