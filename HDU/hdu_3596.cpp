#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <complex>
#include <algorithm>
#include <cmath>
#include <cstring>
#define MAXN 10002
#define LB 3
#define RB (-3)
#define INF 1<<30
using namespace std;

double eps = 1e-10;
char s[MAXN],t[MAXN];
int f[MAXN],sr;
bool flag;

double Calc( int l, int r )
{
	int i, k, min = INF;
	if( r < l ) return 0.0;
	for( i = r; i >= l; i-- )  //由于有“-”，故要从右向左扫描
	{
		if( min > f[i] )
		{
			min = f[i];
			k = i;
		}
	}
	if( min == INF )
	{
		double sum = 0;
		for( i = l; s[i] != '.' && i <= r; i++ )
			sum = sum * 10 + s[i] - '0';
		if( i <= r )
		{
			double e = 0.1;
			for( int j = i + 1; j <= r; j++ )
				sum += ( s[j] - '0' ) * e, e /= 10;
		}
		return sum;
	}
	double t1, t2;
	switch(s[k])
	{
	case '+':
		{
			t1 = Calc( l, k - 1 );
			t2 = Calc( k + 1, r );
			return t1 + t2;
		}
	case '-':
		{
			t1 = Calc( l, k - 1 );
			t2 = Calc( k + 1, r );
			return t1 - t2;
		}
	case '*':
		{
			t1 = Calc( l, k - 1 );
			t2 = Calc( k + 1, r );
			return t1 * t2;
		}
	case '/':
		{
			t1 = Calc( l, k - 1 );
			t2 = Calc( k + 1, r );
			if( fabs( t2 ) < eps )
			{
				flag = false;
				//goto finish;
			}
			return t1 / t2;
		}
	case '^':
		{
			t1 = Calc( l, k - 1 );
			t2 = Calc( k + 1, r );
			return pow( t1, t2 );
		}
	}
}

int main(int argc, char *argv[])
{
	int fi,i;
	while( gets(t) )
	{
		sr = -1; fi = 0;
		int len = strlen(t);
		for( i = 0; i < len; i++ )
		{
			if( t[i] == '(' )  fi += LB;
			else if( t[i] == ')' )  fi += RB;
			else if( t[i] != ' ' )
			{
				s[++sr] = t[i];
				switch( t[i] )
				{
				case '+': f[sr] = fi; break;
				case '-': f[sr] = fi; break;
				case '*': f[sr] = fi + 1; break;
				case '/': f[sr] = fi + 1; break;
				case '^': f[sr] = fi + 2; break;
				//case '.': break;
				default : f[sr] = INF; break;
				}
			}
		}
		flag = true;
		double ans = Calc( 0, sr );
//finish:
		if( !flag )printf("The teacher is so lazy!\n");
		else printf("%.8lf\n",ans);

	}
	return 0;
}
