#include<iostream>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;
priority_queue< int, vector<int>, greater<int> > heap;

int main( )
{
	int i,a1,len,sum,x,y,t;
	string str;
	int a[30];
	while( cin>>str && str != "END" )
	{
		len = str.size( );
		a1 = len * 8;
		memset( a, 0, sizeof(a) );
		for( i=0; i<len; i++ )
		{
			if( str[i]=='_' )a[26]++;
			else a[str[i]-'A']++;
		}
		for( i=0; i<=26; i++ )
			if( a[i] )heap.push( a[i] );
		if( heap.size( ) == 1 )sum=heap.top( );
		else sum=0;
		while( heap.size( ) != 1 )
		{
			x=heap.top( );
			heap.pop( );
			y=heap.top( );
			heap.pop( );
			t = x + y; 
			sum += t;
			heap.push( t );
		}
		heap.pop( );
		printf("%d %d %.1lf\n",a1,sum,a1*1.0/sum);
	}
	return 0;
}