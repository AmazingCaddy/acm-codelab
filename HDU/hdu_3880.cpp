/*
    author: AmazingCaddy
    time:    2011-07-27 20:10:21 
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <complex>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <map>
using namespace std;
typedef long long ll;

int main(int argc, char *argv[])
{
    ll a, b, M;
    while( cin >> a >> b >> M )
    {
        if( a == b )
        {
            cout << M << "\n";
            continue;
        }
        ll tmp = max( a, b );
        ll d = tmp, flag = 1, ans = 0;
        while( d <= M )
        {
            ans = ans + ( M / d ) * flag;
            flag = -flag;
            d *= tmp;
        }
        cout << ans << "\n";
    }
    return 0;
}