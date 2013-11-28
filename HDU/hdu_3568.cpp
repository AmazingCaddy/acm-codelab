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
const int maxn = 100005;
int r[maxn], b[maxn];

int main(int argc, char *argv[])
{
    int cas, n;
    ll sum;
    scanf("%d",&cas);
    for( int k = 1; k <= cas; k++ )
    {
        scanf("%d",&n);
        sum = 0;
        for( int i = 0; i < n; i++ )
        {
            scanf("%d%d",&r[i],&b[i]);
            sum += b[i];
        }
        ll ans = 0;
        for( int i = 0; i < n; i++ )
            ans = ans + (ll)r[i] * ( sum - b[i] );
        printf("Case %d: %I64d\n",k,ans);
    }
    return 0;
}
