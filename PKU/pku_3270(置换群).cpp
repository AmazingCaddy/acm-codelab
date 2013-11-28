/*
    author: wwb
    time: 25/02/2011 15:35:35 
    黑书 P248 对于每一个循环，设它长度为ki，容易证明至少需要交换ki-1次，
    一个比较好的方法就是让循环中最小的元素ti参与所有的交换，其他元素之参加一次，
    因此总的花费是 sumi+(ki-2)*ti 其中sumi是循环中所有数的和。
    但是我们还可以借助循环外的数和它们交换，我们可以让ti先和所有n个数中的最小值m交换，
    让m进入循环，并和剩下的ki-1个元素交换一次，最后再让m和ti交换，sumi+ti+(ki+1)*m
    cost = sum + sigma min{ (ki-1)*ti, ti+(ki+1)*m }
*/
#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <complex>
#include <cstdlib>
#include <map>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 10005;
const int inf = 0x3fffffff;
struct node { int id, val; };
node a[ maxn ];
int vis[ maxn ];

bool cmp( const node & a, const node & b )
{
    return a.val < b.val;
}

int main( int ac, char *av[ ] )
{
    int n, MMin, sum;
    while( scanf( "%d", &n ) != EOF )
    {
        MMin = inf;
        for( int i = 0; i < n; i++ )
        {
            scanf( "%d", &a[ i ].val );
            if( a[ i ].val < MMin ) MMin = a[ i ].val;
            a[ i ].id = i;
        }
        sort( a, a + n, cmp );
        memset( vis, 0, sizeof( vis ) );
        sum = 0;
        for( int i = 0; i < n; i++ )
        {
            if( vis[ i ] ) continue;
            int Min = a[ i ].val, pos = i, cnt = 0;
            sum += a[ i ].val;
            vis[ pos ] = 1;
            while( a[ pos ].id != i )
            {
                pos = a[ pos ].id;
                vis[ pos ] = 1;
                sum += a[ pos ].val;
                if( Min > a[ pos ].val ) Min = a[ pos ].val;
                cnt++;
            }
            sum += min( ( cnt - 1 ) * Min, Min + ( cnt + 2 ) * MMin );
        }
        printf( "%d\n", sum );
    }
    return 0;
}

