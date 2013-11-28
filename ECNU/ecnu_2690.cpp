#include<iostream>
using namespace std;
int main()
{
	int e,f,c;
	int sum,ans;
	while( scanf("%d%d%d",&e,&f,&c) != EOF )
	{
		sum=e+f;
		ans=0;
		while( sum >= c )
		{
			ans=ans+sum/c;
			sum=sum/c+sum%c;
		}
		printf("%d\n",ans);
	}
	return 0;
}