#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int maxn = 200;
char ch[20][maxn];

int main( )
{
	int cas, s, t;
	//freopen("out.txt","w",stdout);
	scanf("%d",&cas);
	for( int p = 1; p <= cas; p++ )
	{
		scanf("%d%d",&s,&t);
		int ss = s * 2 + 3;
		getchar( );
		for( int i = 0; i < ss; i++ )
			gets( ch[i] );
		int slen = s + 3;
		int len = strlen( ch[0] );
		printf("Case %d:\n",p);
		for( int j = 0; j < len; j += slen )
		{
			printf("%c",ch[0][j]);
			char tmp = ch[0][j+1];
			for( int k = 0; k < t; k++ )
				printf("%c",tmp);
			printf("%c",ch[0][j+slen-2]);
			if( j + slen < len )printf(" ");
		}
		printf("\n");
		for( int i = 0; i < t; i++ )
		{
			for( int j = 0; j < len; j += slen )
			{
				printf("%c",ch[1][j]);
				char tmp = ch[1][j+1];
				for( int k = 0; k < t; k++ )
					printf("%c",tmp);
				printf("%c",ch[1][j+slen-2]);
				if( j + slen < len )printf(" ");
			}
			printf("\n");
		}
		for( int j = 0; j < len; j += slen )
		{
			printf("%c",ch[s+1][j]);
			char tmp = ch[s+1][j+1];
			for( int k = 0; k < t; k++ )
				printf("%c",tmp);
			printf("%c",ch[s+1][j+slen-2]);
			if( j + slen < len )printf(" ");
		}
		printf("\n");
		for( int i = 0; i < t; i++ )
		{
			for( int j = 0; j < len; j += slen )
			{
				printf("%c",ch[s+2][j]);
				char tmp = ch[s+2][j+1];
				for( int k = 0; k < t; k++ )
					printf("%c",tmp);
				printf("%c",ch[s+2][j+slen-2]);
				if( j + slen < len )printf(" ");
			}
			printf("\n");
		}
		for( int j = 0; j < len; j += slen )
		{
			printf("%c",ch[ss-1][j]);
			char tmp = ch[ss-1][j+1];
			for( int k = 0; k < t; k++ )
				printf("%c",tmp);
			printf("%c",ch[ss-1][j+slen-2]);
			if( j + slen < len )printf(" ");
		}
		printf("\n\n");
	}
	return 0;
}
