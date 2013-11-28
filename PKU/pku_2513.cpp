#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

const int maxn = 550020;
struct TireNode
{
	int id;
	TireNode *child[26];
}T[maxn];
struct node
{
	int x, y;
}pp[maxn>>1];

int f[maxn], rank[maxn], d[maxn];
int len, num;

TireNode * NewTireNode( )
{
	T[len].id = 0;
	for( int i = 0; i < 26; i++ )
		T[len].child[i] = NULL;
	return &T[len++];
}

void init( )
{
	T[0].id = 0;
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
	return p -> id;
}

int insert( char ch[] )
{
	int k;
	TireNode * p = &T[0];
	for( int i = 0; ch[i]; i++ )
	{
		k = ch[i] - 'a';
		if( p -> child[k] == NULL ) p -> child[k] = NewTireNode( );
		p = p -> child[k];
	}
	if( p -> id == 0 ) p -> id = num++;
	return p -> id;
}

void union_init( )
{
	for( int i = 0; i < maxn; i++ )
		f[i] = i, rank[i] = 1;
}

int find_root( int p )
{
	if( f[p] != p ) f[p] = find_root( f[p] );
	return f[p];
}

void Union( int x, int y )
{
	int a = find_root( x ), b = find_root( y );
	if( a != b )
	{
		if( rank[a] < rank[b] ) f[a] = b;
		else if( rank[a] > rank[b] ) f[b] = a;
		else rank[a]++, f[b] = a;
		num--;
	}
}

int main( )
{
	int id1, id2, k = 1;
    char ch1[20], ch2[20];
	init( );
	union_init( );
	num = 1;
	memset( d, 0, sizeof( d ) );
    while( scanf("%s%s",ch1,ch2) != EOF )
	{
		id1 = insert( ch1 );
		id2 = insert( ch2 );
		d[id1]++;
		d[id2]++;
		pp[k].x = id1, pp[k].y = id2;
		k++;
	}
	if( k == 1 )
	{
		printf("Possible\n");
		return 0;
	}
	int tmp = num;
	for( int i = 1; i < k; i++ )
		Union( pp[i].x, pp[i].y );
	if( num == 2 )
	{
		num = tmp;
		int sum = 0;
		for( int i = 1; i < num; i++ )
			if( d[i] % 2 ) sum++;
		if( sum == 2 || sum == 0 ) printf("Possible\n");
		else printf("Impossible\n");
	}
	else printf("Impossible\n");
    return 0;
}
