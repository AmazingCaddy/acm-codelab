/*
    author: wwb
    time: 25/02/2011 15:35:35 
    ���� P248 ����ÿһ��ѭ������������Ϊki������֤��������Ҫ����ki-1�Σ�
    һ���ȽϺõķ���������ѭ������С��Ԫ��ti�������еĽ���������Ԫ��֮�μ�һ�Σ�
    ����ܵĻ����� sumi+(ki-2)*ti ����sumi��ѭ�����������ĺ͡�
    �������ǻ����Խ���ѭ������������ǽ��������ǿ�����ti�Ⱥ�����n�����е���Сֵm������
    ��m����ѭ��������ʣ�µ�ki-1��Ԫ�ؽ���һ�Σ��������m��ti������sumi+ti+(ki+1)*m
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

