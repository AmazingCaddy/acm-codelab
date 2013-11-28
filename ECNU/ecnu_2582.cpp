#include<iostream>
#include<map>
#include<queue>
#include<algorithm>
#define M 10000
using namespace std;
map< int, queue<int> > num;
int main()
{
	int i,n,m;
	int a[M],b[M];
	scanf("%d",&n);
	while( n-- )
	{
		scanf("%d",&m);
		for( i=0; i<m; i++ )
		{
			scanf("%d",&a[i]);
			b[i]=a[i];
		}
		sort( a, a+m );

		for( i=0; i<m; i++ )
			num[a[i]].push( i );

		for( i=0; i<m; i++ )
		{
			if( i )cout<<" ";
			cout<<num[b[i]].front( );
			num[b[i]].pop( ); 
		}
		cout<<endl;
		num.erase( num.begin(), num.end() );
	}
	return 0;
}