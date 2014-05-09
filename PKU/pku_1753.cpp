#include <iostream>
#include <queue>
using namespace std;
struct Node
{
	int x;
	int steps;
};
bool visit[65540];
int Change( int num, int i ) //改变第K位，从第零位开始
{
	num ^= ( 1 << i );
	if( i - 4 >= 0 )
		num ^= ( 1 << ( i - 4 ) );
	if( i + 4 <= 15 )
		num ^= ( 1 << ( i + 4 ) );
	if( i % 4 != 0 )
		num ^= ( 1 << ( i - 1 ) );
	if( i % 4 != 3 )
		num ^= ( 1 << ( i + 1 ) );
	return num;
}
int Search( int oo )
{   
	Node no,tno;
	int i;
	queue<Node> nums;
	memset( visit, false, sizeof(visit) );
	no.x = oo;
	no.steps = 0;
	nums.push( no );
	visit[no.x] = true;
	while( !nums.empty( ) )
	{
		no=nums.front( );
		if( no.x==0 || no.x==65535 )
			return no.steps;
		nums.pop( );
		tno.steps = no.steps + 1;
		for( i=0; i<=15; i++ )
		{
			tno.x = Change( no.x, i );           
			if( !visit[tno.x] )
			{
				nums.push( tno );
				visit[tno.x] = true;
			}
		}
	}
	return -1;
}
int main( )
{
	char s[6];
	int x=0,i,t; //存储状态
	int counts=0;  
	while( scanf("%s",s) != EOF )
	{   
		for( i=0; i<4; i++ )
		{
			x<<=1;       
			if( s[i]=='b' )
				x += 1;      
		}
		counts++;
		if( counts==4 )
		{
			counts=0;
			t=Search( x );
			if( t==-1 ) printf("Impossible\n");	
			else printf("%d\n",t);
			x=0;
		}
	}
	return 0;
}
