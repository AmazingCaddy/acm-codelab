#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

const int maxn = 200020;
struct TireNode
{
	int cnt;
	TireNode *child[26];
}T[maxn];

int len;

TireNode * NewTireNode( )
{
	T[len].cnt = 0;
	for( int i = 0; i < 26; i++ )
		T[len].child[i] = NULL;
	return &T[len++];
}

void init( )
{
	T[0].cnt = 0;
	for( int i = 0; i < 26; i++ )
		T[0].child[i] = NULL;
	len = 1;
}

int find( char ch[] )
{
	int k;
	TireNode * p = &T[0];
	for( int i = 0; ch[i]; i++ )
	{
		if( p -> child[ch[i]-'a'] ) p = p -> child[ch[i]-'a'];
		else return 0;
	}
	return p -> cnt;
}

void insert( char ch[], int id )
{
	int k;
	TireNode * p = &T[0];
	for( int i = 0; ch[i]; i++ )
	{
		k = ch[i] - 'a';
		if( p -> child[k] == NULL ) p -> child[k] = NewTireNode( );
		p = p -> child[k];
		// p -> cnt++;
	}
	p -> cnt = id;
}

char str[ maxn ][ 11 ];
int main( )
{
	int id = 1;
	char s[ 100 ];
	str[ 0 ][ 0 ] = 'e', str[ 0 ][ 1 ] = 'h', str[ 0 ][ 2 ] = 0;
	while( gets( s ) )
	{
		if( !*s )break;
		sscanf( s, "%s%s", str[id], s );
		insert( s, id );
		id++; 
	}
	while( scanf("%s",s) != EOF )
	{
		id = find( s );
		printf("%s\n",str[id]);
	}
	return 0;
}
