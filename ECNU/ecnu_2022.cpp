#include<iostream>
#include<algorithm>
#define MAXN 50005
using namespace std;
struct node
{
	int A,B,ID;
	bool operator<( const node &a )
	{
		return a.A<A;
	}
};

node vote[MAXN];
int main( )
{
	int n,k,ID,i,max;
	while( scanf("%d%d",&n,&k) != EOF )
	{
		for( i=0; i<n; i++ )
		{
			scanf("%d%d",&vote[i].A,&vote[i].B);
			vote[i].ID=i+1;
		}
		sort( vote, vote+n );
		max=0;ID=1;
		for( i=0; i<k; i++ )
			if( vote[i].B>max )
				max=vote[i].B,ID=vote[i].ID;
		printf("%d\n",ID);
	}
	return 0;
}