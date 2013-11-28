#include <cstdio>
#include <iostream>
#include <cmath>
#include <complex>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

const int maxn = 100010;
int dp1[maxn], dp2[maxn];

int main(int argc, char *argv[])
{
    int i, j, k, n, val, m, w, v, z;
    while( scanf("%d%d",&n,&val) != EOF )
    {
        memset( dp1, 0, sizeof( dp1 ) );
        for( i = 0; i < n; i++ )
        {
            scanf("%d%d",&z,&m);
            for( j = 0; j <= z; j++ )
                dp2[j] = 0;
            for( j = z + 1; j <= val; j++ )
                dp2[j] = dp1[j-z];
            for( j = 0; j < m; j++ )
            {
                scanf("%d%d",&w,&v);
                for( k = val; k >= z + w; k-- )
                    if( dp2[k-w] + v > dp2[k] )
                        dp2[k] = dp2[k-w] + v;
            }
            for( j = 0; j <= val; j++ )
                if( dp1[j] < dp2[j] )
                    dp1[j] = dp2[j];
        }
        printf("%d\n",dp1[val]);
    }
    return 0;
}
