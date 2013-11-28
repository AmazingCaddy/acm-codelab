#include<iostream>
#include<string.h>
#define MAXN 202
#define LB 2
#define RB (-2)
#define INF 1<<30
using namespace std;

char s[MAXN],t[MAXN];
int f[MAXN],sr;

int Calc( int l, int r )
{
	int i,k,min=INF;
	for( i=r; i>=l; i-- )  //由于有“-”，故要从右向左扫描
	{
		if( min>f[i] )
		{
			min=f[i];
			k=i;
		}
	}
	if( min==INF )
	{
		k=0;
		for( i=l; i<=r; i++ )
			k=k*10+s[i]-'0';
		return k;
	}
	switch(s[k])
	{
	case '+':return Calc( l, k-1 ) + Calc( k+1, r );
	case '-':return Calc( l, k-1 ) - Calc( k+1, r );
	case '*':return Calc( l, k-1 ) * Calc( k+1, r );
	case '/':return Calc( l, k-1 ) / Calc( k+1, r );
	}
}

int main( )
{
	int fi,i;
	while( gets(t) )
	{
		sr=-1;fi=0;
		for( i=0; i<strlen(t); i++ )
		{
			if( t[i]=='(' )  fi+=LB;
			else if( t[i]==')' )  fi+=RB;
			else if( t[i]!=' ' )
			{
				s[++sr]=t[i];
				switch(t[i])
				{
				case '+': f[sr]=fi;break;
				case '-': f[sr]=fi;break;
				case '*': f[sr]=fi+1;break;
				case '/': f[sr]=fi+1;break;
				default : f[sr]=INF;break;
				}
			}
		}
		printf("%d\n",Calc( 0, sr ));
	}
	return 0;
}