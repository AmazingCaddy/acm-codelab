/*
    author: AmazingCaddy
    time: 27/05/2011 16:02:12 
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int maxn = 1004;
char mn[ maxn ],tem[ maxn ];

int main( )
{
    int n, i, k;

    scanf( "%d%*c", &n ); // *
    while( n-- )
    {
        gets( mn );
        k = 0;
        for( i = 0; ( mn[ i ] ) != '\n'; i++ )
        {
            tem[ k ] = mn[ i ];
            k++;
            if( mn[ i ]==' '|| mn[ i ] == '\0' ) // *
            {
                tem[ k - 1 ] = '\0'; // Ò»¸öµ¥´Ê½áÊø
                reverse( tem, tem + k - 1 );
                printf( "%s", tem ); //* µ¹ÖÃ×Ö·û´®
                if( mn[ i ] == '\0' ) break;
                else printf( " " );
                k = 0;
            }
        }
        printf( "\n" );
    }
    return 0;
}

