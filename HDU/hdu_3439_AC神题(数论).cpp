//  ans = C( n, n - k ) * DP( n - k ) % m
//  C( n, m ) = F[n] * Inv(F[m]) * Inv(F[n-m]) * p^cnt ( mod p^k )
//  cnt 表示C( n, m )分解质因数之后p指数

#include<iostream>
#include<ctime>
using namespace std;

typedef long long LL;

const int maxn = 100005;
const int maxm = 405;
bool ss[maxm] = {1,1};
int pp[maxm >> 1],plen = 0;
int fac[32][2],flen ;
int F[maxn],Inv[maxn];
int DP[maxn << 1];     // 记录全错排的数量
int n, k, m;

LL cnt_of_p;
int p,P;

// 刷一个比较小的素数表
void mklist(){
	int i,j;
	for(i = 2; i * i < maxm; ++ i) if(! ss[i]) for(j = i; j * i < maxm; ++ j) ss[i * j] = 1;
	for(i = 2; i < maxm; ++ i) if(! ss[i]) pp[plen ++]  =  i;
}

// 分解质因数
void split(int n)
{
	flen= 0;
	int i;
	for(i = 0; i < plen && pp[i] <= n; ++ i)
    {
		if(n % pp[i]) continue;
		fac[flen][0] = pp[i];
		fac[flen][1] = 0;
		while(n % pp[i] == 0) n/= pp[i], ++ fac[flen][1];
		++ flen;
	}
	if(n != 1)
	{
		fac[flen][0] = n;
		fac[flen ++][1] = 1;
	}
}

// a^b mod c
int mod(LL a,int b,int c)
{
	LL ret = 1 % c; 
	while(b)
	{
		if(b&0x1) ret= ret * a % c;
		a = a * a % c;
		b >>=1;
	}
	return ret;
}

// 求 x mod P^k 的逆元, P = p^k, a^-1 = a^(pi(P)-1) = a^(P-P/p-1)
int InvMod( int x ){ return mod( x, P - P / p - 1, P ); }

void init()
{
	F[0] = Inv[0] = 1;cnt_of_p = 0;
	int i,tmp;
	for(i = 1; i < P; ++ i)
	{
		// F[n]表示(n!)中除掉p的倍数之后 mod p^k 的值
		F[i] = F[i - 1];Inv[i] = Inv[ i - 1];
		if(i % p) F[i] = (LL)F[i] * i % P,Inv[i] = (LL)Inv[i] * InvMod(i) % P;
	}
}

// (1 * 2 * 3 * ... * n) mod P, P = p ^ cntk
int cal_fac_modP(int n)
{
	if(n <= 1) return 1;
	LL ans = 1;
	int cnt_of_seg = n / P,cnt_of_rem = n % P;
	ans = mod(F[P - 1], cnt_of_seg, P);
	ans = ans * F[cnt_of_rem] % P;
	cnt_of_p += n /= p;
	ans = ans * cal_fac_modP(n ) % P;
	return ans;
}

// Inv(1 * 2 * 3 * ... * n) mod P, P = p ^ cntk
int cal_inv_modP(int n)
{
	if(n <= 1) return 1;
	LL ans = 1;
	int cnt_of_seg = n / P,cnt_of_rem = n % P;
	ans = mod(Inv[P - 1], cnt_of_seg, P);
	ans = ans * Inv[cnt_of_rem] % P;
	cnt_of_p -= n /= p;
	ans = ans * cal_inv_modP(n ) % P;
	return ans;
}

int ext_gcd( int a, int b, int &x, int &y )
{
	int t, d;
	if( b == 0 ) { x = 1; y = 0; return a; }
	d = ext_gcd( b, a % b, x, y );
	t = x;
	x = y;
	y = t - a / b*y;
	return d;
}

int CTR( int b[], int w[], int k )
{
	int i;
	int d, x, y, a = 0, m, n = 1;
	for( i = 0; i < k; i++ ) n *= w[i];
	for( i = 0; i < k; i++ )
	{
		m = n / w[i];
		d = ext_gcd(w[i], m, x, y);
		LL yy = y; yy = yy * m % n; yy = yy * b[i] % n;
		a = (a + yy) % n;
	}
	if (a >= 0) return a;
	else return (a + n);
}

int Cal_Cnk_mod_P_K(int n,int k,int _p,int _P)
{
	p = _p;
	P = _P;
	init();
	LL ans = cal_fac_modP(n);
	ans = ans * cal_inv_modP(k)% P;
	ans = ans * cal_inv_modP(n - k)% P;
	ans = ans * mod(p,cnt_of_p,P) % P;
	return ans ;
}

int b[55],w[55];
int idx = 0;

void work()
{
	++ idx;
	printf("Case %d: ",idx);
	if(m == 1)
	{
		puts("0");
		return;
	}
	k = n - k;
	if(k == 0)
	{
		puts("1");
		return ;
	}	
	if(k == 1) 
	{
		puts("0");
		return ;
	}
	int i,j;
	for(i = 0; i < flen; ++ i)
	{
		w[i] = 1;
		for(j = 0; j < fac[i][1]; ++ j) w[i] *= fac[i][0];
		b[i] = Cal_Cnk_mod_P_K(n,k,fac[i][0],w[i]);
	}
	LL ans = CTR(b,w,flen);
	int cnt_of_seg,cnt_of_rem;
	DP[0] = 1; DP[1] = 0;
	for(i = 2; ; ++ i)
	{
		DP[i] = (LL)(i - 1) * (DP[i - 1] + DP[i - 2]) % m;
		if(DP[i - 1] == 1 && DP[i] == 0 && i % m == 1)
		{
			cnt_of_seg = i - 1;
			break;
		}
	}
	//cout <<"ans = " << ans <<endl;
	//cout <<"cnt_of_seg = " << cnt_of_seg <<endl;
	cnt_of_rem =k % cnt_of_seg;
	ans = ans * DP[cnt_of_rem] % m;
	printf("%I64d\n",ans);
}

void get( ){ scanf("%d%d%d",&n,&k,&m); }
int main()
{
	//freopen("D:\\in.txt","r",stdin);
	//freopen("D:\\out.txt","w",stdout);
	mklist();
	int T;
	scanf("%d",&T);
	while(T --)
	{
		get();
		split(m);
		work();
	}
	//cout <<clock() <<"ms "<<endl;
	return 0;
}