// AC��ţ�Ĳ��� http://hi.baidu.com/aekdycoin/blog/item/63f633ec11c822d8b21cb168.html
// �õ� n�ڵ� ���������Լ�ÿ�������ڵĺ�(���ѵõ�)
// �������Ҫ�������� ������
// ����
// n - spos ��һ���� Slen ��������,��������Ҫ����
// (n - Spos) / Slen  ������ȡ���Ľ��(����������)
// (n - Spos) % Slen = C ��ʾ���ʣ����Ǹ�����������

// �������������ܴ��������ֻ��Ҫ���� ������  mod P
// ��ô������ôת��
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

// ���� 1 + Q + Q^2 + Q^3 + ... + Q^n;
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
//  Spos�ܹ����һ���Ƚ�С����
ll cal( ll & res_seg )  // res_seg Ϊ C 
{
    ll mod_res = ( pow_mod( 2, Y2, Slen ) + Z2 ) % Slen;
    res_seg = mod_res = MOD( mod_res - Spos, Slen );
    ll ret = Bpow_mod( 2, Y2, HP ) - Spos - mod_res + Z2; 
    ret = MOD( ret, HP ) / Slen;
    return ret; // ���������� mod P֮�������
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
    if( Y2 <= 10 )   // �����ݱȽ�С��ʱ��ֱ�Ӽ���
    {
        limit = ( 1 << Y2 ) + Z2;
        for( ret = 0, v = 1 % P, i = 0; i < limit; v = v * Q % P, i++ )
            ret = ( ret + v ) % P;
        if( limit & 1 ) printf("%I64d\n",ret);
        else printf("%I64d\n",P - ret);
        return ;
    }
	// ��Ϊ���μ���
    limit = Spos;
    // ��һ�� ���㲻��ѭ������֮�ڵ���֮�� mod P
    for( ret = 0, v = 1 % P, i = 0; i < limit; v = v * Q % P, i++ )
        ret = ( ret + v ) % P;
    // �ڶ��� ����һ�������ڵ���֮�� mod P
    ll seg_sum = sum( Slen - 1 ) * pow_mod( Q, Spos, P ) % P;
    ll res_seg;
    ss = cal( res_seg );
    ret = ( ret + seg_sum * ss % P ) % P;
	// ������ ����ʣ�µĲ����������ڵĺ�
    ret = ( ret + sum ( res_seg - 1 ) * pow_mod( Q, Spos, P ) % P ) % P;
    if( Z2 & 1 ) printf("%I64d\n",ret);
    else printf("%I64d\n",P-ret);
}

int main( int argc, char *argv[] )
{
    while( Read( ) )solve( );
    return 0;
}
