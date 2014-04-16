#include <iostream>
#include <string.h>
#define MAXN 2002
#define  LB   3
#define  RB   (-3)
#define  OO   2123456789

char  s[MAXN],t[MAXN];
int   f[MAXN],sr;

bool Calc( int l, int r )
{
	int i, k, min = OO;
	for( i=r; i>=l; --i )
	{
		if( min > f[i] )
		{
			min = f[i];
			k   = i;
		}
	}
	if( min == OO )
	{
		if( s[l]=='F' )return false;
		else return true;
	}
	switch( s[k] )
	{
	case '!' : return !Calc( k+1, r );
	case '&' : return Calc( l, k-1 ) & Calc( k+1, r );
	case '|' : return Calc( l, k-1 ) | Calc( k+1, r );
	}
}

int main( )
{
	int i, fi=0, sr, k=1;
	while( gets(t) )
	{
		sr=-1;
		for( i=0; i<strlen(t); i++ )
		{
			if( t[i] == '(' )   fi += LB;
			else if( t[i] == ')' )	fi += RB;
			else if( t[i] != ' ' )
			{
				s[++sr] = t[i];
				switch( t[i] )
				{
				case '!' : f[sr] = fi + 2; break;
				case '|' : f[sr] = fi + 0; break;
				case '&' : f[sr] = fi + 1; break;
				default :  f[sr] = OO;     break;
				}
			}
		}
		if( Calc( 0, sr ) )printf("Expression %d: V\n",k++);
		else printf("Expression %d: F\n",k++);
	}
	return 0;
}
