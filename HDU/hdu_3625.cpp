#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <complex>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
typedef __int64 ll;

const int maxn = 25;

ll s[maxn][maxn];
ll N[maxn];

void init( )
{
    memset( s, 0, sizeof( s ) );
    s[0][0] = 0;
    for( int i = 1 ; i <= 20; i++ )
        s[i][0] = 0, s[i][i] = 1;
    for( int i = 2; i <= 20; i++ )
        for( int j = 1; j < i; j++ )
            s[i][j] = s[i-1][j-1] + (i - 1) * s[i-1][j];
    N[0] = 1;
    for( int i = 1; i <= 20; i++ )
        N[i] = N[i-1] * i;
}

int main(int argc, char *argv[])
{
    int cas, n, k;
    init( );
    scanf("%d",&cas);
    while( cas-- )
    {
        scanf("%d%d",&n,&k);
        ll sum = 0;
        for( int j = 1; j <= k; j++ )
            sum += ( s[n][j] - s[n-1][j] );
        sum += s[n-1][k];
        double ans = sum * 1.0 / N[n];
        printf("%.4lf\n",ans);
    }
    return 0;
}
