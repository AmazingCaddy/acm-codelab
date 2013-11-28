#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <complex>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 100005;
const double eps = 1e-8;

const char * one[ ] = {	"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };
const char * ten[ ] = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
const char * hun[ ] = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
const char * tho[ ] = { "", "M", "MM", "MMM" };

struct node
{
    string str;
    int id;
};
vector< node > ve;

bool cmp( const node &a, const node &b )
{
    return a.str < b.str;
}

string change( int n )
{
    string str;
    while( n )
    {
        if( n >= 1000 )
        {
            str = str + tho[ n / 1000 ];
            n %= 1000;
        }
        else if( n >= 100 )
        {
            str = str + hun[ n / 100 ];
            n %= 100;
        }
        else if( n >= 10 )
        {
            str = str + ten[ n / 10 ];
            n %= 10;
        }
        else
        {
            str = str + one[ n ];
            n = 0;
        }
    }
    return str;
}

int main( )
{
    int cas, n, x;
    node tmp;
    scanf( "%d", &cas );
    while( cas-- )
    {
        scanf( "%d", &n );
        ve.clear( );
        for( int i = 0; i < n; i++ )
        {
            scanf( "%d", &x );
            tmp.id = x;
            tmp.str = change( x );
            ve.push_back( tmp );
        }
        sort( ve.begin( ), ve.end( ), cmp );
        for( int i = 0; i < ve.size( ); i++ )
        {   
            if( i ) printf( " " );
            printf( "%d", ve[ i ].id );
        }
        printf( "\n" );
    }
    return 0;
}
