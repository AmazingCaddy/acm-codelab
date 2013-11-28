#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 103;

int A[ maxn ][ maxn ], B[ maxn ][ maxn ];
int n, K;

int solve( )
{
    int dif = 0, cnt = 0;
    for( int i = 0; i < n; i++ )
        for( int j = 0; j < n; j++ )
        {
            if( A[ i ][ j ] != B[ i ][ j ] ) dif++;
            if( B[ i ][ j ] != B[ j ][ i ] ) cnt++;
        }
    
    if( !dif ) return 0;
    if( !cnt ) return -1;
    
    int cnt1 = 0, cnt2 = 0;
    for( int i = 0; i < n; i++ )
    {
        for( int j = i + 1; j < n; j++ )
        {
            if( B[ i ][ j ] != B[ j ][ i ] )
            {
                cnt1++;
                if( !( A[ i ][ j ] == B[ j ][ i ] && A[ j ][ i ] == B[ i ][ j ] ) )
                    return dif;
            }
            else 
            {
                cnt2++;
                if( A[ i ][ j ] != B[ i ][ j ] || A[ j ][ i ] != B[ i ][ j ] )
                    return dif;
            }
        }
    }

    if( !cnt1 ) return -1;
    if( cnt1 > 1 ) return dif;
    
    if( K == 2 ) // cnt1 == 1 
    {
        if( cnt2 == 0 ) // cnt1 + cnt2 == 1
            return -1;
        return dif + 2;
    }
    return dif + 1;
}

int main( )
{
    int cas;
    scanf("%d",&cas);
    for( int t = 1; t <= cas; t++ )
    {
        scanf("%d%d",&n,&K);
        for( int i = 0; i < n; i++ )
            for( int j = 0; j < n; j++ )
                scanf("%d",&A[i][j]);
        for( int i = 0; i < n; i++ )
            for( int j = 0; j < n; j++ )
                scanf("%d",&B[i][j]);
        printf("Case %d: %d\n",t,solve( ));
    }
    return 0;
}
