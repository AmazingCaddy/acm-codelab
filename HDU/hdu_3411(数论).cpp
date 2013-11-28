// AC大牛的博文 http://hi.baidu.com/aekdycoin/blog/item/63f633ec11c822d8b21cb168.html
// 得到 n内的 周期数，以及每个周期内的和(不难得到)
// 这里的主要问题是求 周期数
// 由于
// n - spos 不一定是 Slen 的整数倍,而我们需要的是
// (n - Spos) / Slen  的向下取整的结果(完整周期数)
// (n - Spos) % Slen = C 表示最后剩余的那个不完整周期

// 而由于周期数很大，因此我们只需要计算 周期数  mod P
// 那么可以这么转化
// ( n - Spos - C ) / Slen % P -> ( n - Spos - C ) % ( P * Slen ) / Slen

#include <stdio.h>
#include <iostream>
using namespace std;

typedef __int64 ll;
ll Spos, Slen;
ll X1, Y1, Z1, Y2, Z2;
ll HP, P, Q;;

template<class T> T MOD( T a, T b ){ a %= b; return a < 0 ? a + b : a; }

ll phi( ll n )
{
    ll ret = n;
    int i, j;
    for( i = 2, j = 4; j <= n; i++, j += i + i - 1 )
    {
        if( !( n % i ) )
        {
            ret = ret / i * ( i - 1 );
            while( !( n % i ) ) n /= i;
        }
    }
    if( n > 1 ) ret = ret / n * ( n - 1 );
    return ret;
}

ll pow_mod( ll a, ll b, ll c )
{
    ll ans = 1, d = a % c;
    while( b )
    {
        if( b & 1 ) ans = d * ans % c;
        d = d * d % c;
        b >>= 1;
    }
    return ans;
}

ll mul_mod( ll a, ll b, ll c )
{
    ll ans = 0, d = a % c;
    while( b )
    {
        if( b & 1 )if( ( ans += d ) >= c ) ans -= c;
        if( ( d <<= 1 ) >= c ) d -= c;
        b >>= 1;
    }
    return ans ;
}

ll Bpow_mod( ll a, ll b, ll c )
{
    ll ans = 1, d = a % c;
    while( b )
    {
        if( b & 1 ) ans = mul_mod( ans, d, c );
        d = mul_mod( d, d, c );
        b >>= 1;
    }
    return ans;
}

// 计算 1 + Q + Q^2 + Q^3 + ... + Q^n;
ll sum( ll n )
{
    ll S;
    if( n < 0 ) return 0;
    if( n == 0 ) return 1 % P;
    if( n == 1 ) return ( 1 + Q ) % P;
    if( n & 1 )
    {
        S = sum( n >> 1 );
        return ( S + S * pow_mod( Q, n / 2 + 1, P ) % P ) % P;
    }
    S = sum( n - 1 );
    return ( S + pow_mod( Q, n, P ) ) % P;
}

int Read( )
{
    scanf("%I64d%I64d%I64d",&X1,&Y1,&Z1);
    if( X1 == -1 && Y1 == -1 && Z1 == -1 ) return 0;
    scanf("%I64d%I64d%I64d",&Y2,&Z2,&P);
    return 1;
}

// ( n - Spos - C ) / Slen % P -> ( n - Spos - C ) % ( P * Slen ) / Slen
//  Spos总归会是一个比较小的数
ll cal( ll & res_seg )  // res_seg 为 C 
{
    ll mod_res = ( pow_mod( 2, Y2, Slen ) + Z2 ) % Slen;
    res_seg = mod_res = MOD( mod_res - Spos, Slen );
    ll ret = Bpow_mod( 2, Y2, HP ) - Spos - mod_res + Z2; 
    ret = MOD( ret, HP ) / Slen;
    return ret; // 返回周期数 mod P之后的余数
}

void solve( )
{ 
    int i;
    ll ret, ss, v, limit; 
    Slen = phi( P );
    HP = (ll)P * Slen;
    Q = ( pow_mod( X1, Y1, P ) + Z1 ) % P;
    Q = MOD( -Q, P );
    for( Spos = 0;  ; Spos++ )
        if( pow_mod( Q, Spos, P ) == pow_mod( Q, Spos + Slen, P ) )break;
    if( Y2 <= 10 )   // 当数据比较小的时候直接计算
    {
        limit = ( 1 << Y2 ) + Z2;
        for( ret = 0, v = 1 % P, i = 0; i < limit; v = v * Q % P, i++ )
            ret = ( ret + v ) % P;
        if( limit & 1 ) printf("%I64d\n",ret);
        else printf("%I64d\n",P - ret);
        return ;
    }
	// 分为三段计算
    limit = Spos;
    // 第一段 计算不再循环周期之内的数之和 mod P
    for( ret = 0, v = 1 % P, i = 0; i < limit; v = v * Q % P, i++ )
        ret = ( ret + v ) % P;
    // 第二段 计算一个周期内的数之和 mod P
    ll seg_sum = sum( Slen - 1 ) * pow_mod( Q, Spos, P ) % P;
    ll res_seg;
    ss = cal( res_seg );
    ret = ( ret + seg_sum * ss % P ) % P;
	// 第三段 计算剩下的不完整周期内的和
    ret = ( ret + sum ( res_seg - 1 ) * pow_mod( Q, Spos, P ) % P ) % P;
    if( Z2 & 1 ) printf("%I64d\n",ret);
    else printf("%I64d\n",P-ret);
}

int main( int argc, char *argv[] )
{
    while( Read( ) )solve( );
    return 0;
}
