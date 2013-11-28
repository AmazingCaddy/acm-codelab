#include<iostream>
#define MAXN 40001
using namespace std;
bool p[MAXN];
int P[6000];
int cnt;
void make_prime( )
{
	int i,j;
	memset( p, true, sizeof(p) );
	p[0]=p[1]=false;
	for( i=2; i<=200; i++ )
		for( j=2; j*i<=40000; j++ )
			p[i*j]=false;
	cnt=0;
	for( i=2; i<=40000; i++ )
		if( p[i] )
			P[cnt++]=i;
}

bool is_prime( int n )
{
	int i;
	for( i=0; i<cnt; i++ )
		if( n%P[i]==0 )return false;
	return true;
}

int main( )
{
	int n,NP,i;
	make_prime( ); 
	scanf("%d",&n);
	while( n-- )
	{
		scanf("%d",&NP);
		for( i=0; i<cnt; i++ )
			if( NP%P[i]==0 )
			{ 
				if( NP/P[i]<=40000 )
				{
					if( p[NP/P[i]] )
						break;
				}
				else if( is_prime( NP/P[i] ) )
					break;
			}
			if( i==cnt )printf("No\n");
			else printf("Yes\n");
	}
	return 0;
}