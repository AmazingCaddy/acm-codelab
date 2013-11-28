#include<iostream>
#include<stack>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#define MP make_pair
using namespace std;
typedef pair<int,int> PII; // first father, second son
const int maxn = 100010;
stack<PII> S;
char buf[maxn];
char a[maxn];

int main( )
{
	//freopen("data.in","r",stdin);
	//freopen("out.txt","w",stdout);
	string text, b;
	int len;
	while( getline( cin, text ) )
	{
		b = text;
		while( getline( cin, text ) )
		{
			if( text == "" )break;
			b += text;
		}
		len = 0;
		while( !S.empty( ) ) S.pop( );
		int num = b.size( );
		int n = 0;
		for( int i = 0; i < num; i++ )
			if( b[i] != ' ' )
				a[n++] = b[i];
		for( int i = 0; i < n; )
		{
			switch( a[i] )
			{
			case 'i':
				buf[len++] = 'I'; // if
				buf[len++] = a[i+3];
				i += 5;
				break;

			case 'w':
				buf[len++] = 'W'; // write
				buf[len++] = a[i+7];
				i += 10;
				break;

			case 'e':
				buf[len++] = 'E'; // else
				i += 4;
				break;
			}
		}
		S.push(MP(1,1));
		PII tmp;
		for( int i = 0; i < len; )
		{
			switch( buf[i] )
			{
			case 'I': // if
				tmp = S.top( );
				i++;
				S.push( MP( tmp.second && tmp.first, buf[i] - '0' ) );
				i++;
				break;

			case 'E': // else
				tmp = S.top( );
				S.pop( );
				i++;
				if( buf[i] == 'W' )
				{
					i++;
					if( tmp.first && ( !tmp.second ) )
						printf("%c\n",buf[i]);
					i++;
				}
				else
				{
					i++;
					S.push( MP( tmp.first && ( !tmp.second ), buf[i] - '0' ) );
					i++;
				}
				break;

			case 'W': // write
				tmp = S.top( );
				i++;
				if( tmp.first && tmp.second )
					printf("%c\n",buf[i]);
				i++;
				break;
			}
		}
	}
	return 0;
}
