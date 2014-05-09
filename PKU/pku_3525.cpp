#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#define MAXN 11000
#define RET return
using namespace std;
typedef double DB;
const DB EPS = 1e-8;
const DB PI = acos(-1.0);
int sign(DB x){if(fabs(x) < EPS)RET 0;RET x<0?-1:1;}
struct TPoint{
	DB x,y;
	TPoint(){}
	TPoint(DB xx,DB yy):x(xx),y(yy){}
	DB cross(TPoint P){RET x*P.y - y*P.x;}
	TPoint operator-(TPoint P){RET TPoint(x-P.x,y-P.y);}
	void IN(){scanf("%lf%lf",&x,&y);}
}a[MAXN],cp[MAXN];
struct TLine{
	DB a;//极角
	TPoint k,d;
	TLine(){}
	TLine(TPoint kk,TPoint dd):k(kk),d(dd),a(atan2(kk.y,kk.x)){}
}L[MAXN];
bool on_left(TPoint d,TLine j){RET sign(j.k.cross(d-j.d)) >= 0;}
bool cmp(TLine i , TLine j)
{
	int c = sign(i.a-j.a);
	if (!c) RET on_left(i.d,j);
	RET c < 0;
}
int Q[MAXN];
bool CrossLine(TLine &i,TLine &j,TPoint &c){
	DB dm = j.k.cross(i.k),ds = j.k.cross(j.d-i.d);
	if (!sign(dm)){
		if (sign(ds)) RET false;
		c = i.d;
	}else{
		DB dt = ds / dm;
		c = TPoint(i.d.x+dt*i.k.x,i.d.y+dt*i.k.y);
	}
	RET true;
}
/*
 *传入切割直线 L[],切割直线集合大小n,切割结果集合cp[],队列的开头和结尾
 *顺序任意
 *复杂度O(nlogn)
 */
bool Cut_HP(TLine L[],int n,TPoint cp[],int Q[MAXN],int &s,int &t){
	int i,j;
	sort(L,L+n,cmp);
	for (i = 1,j = 0;i < n;i++)
		if (sign(L[i].a-L[j].a))
			L[++j] = L[i];
	n = j+1;
	Q[s = 0] = 0,Q[t = 1] = 1;
	if (!CrossLine(L[0],L[1],cp[1])) RET false;
	for (i = 2;i < n;i++){
		while (s < t && !on_left(cp[t],L[i])) t--;
		while (s < t && !on_left(cp[s+1],L[i])) s++;
		Q[++t] = i;
		if (!CrossLine(L[Q[t-1]],L[i],cp[t])) RET false;
	}
	for (bool f = true;f;){
		f = false;
		while (s < t && !on_left(cp[t],L[Q[s]])) t--,f = true;
		while (s < t && !on_left(cp[s+1],L[Q[t]])) s++,f = true;
	}
	if (!CrossLine(L[Q[s]],L[Q[t]],cp[s])) RET false;
	cp[t+1] = cp[s];
	RET s + 1 < t;/*不等式包含等号可行域可以为一个点*/
	/*DB area = 0.0;
	for (i = s;i <= t;i++)
		area += cp[i].cross(cp[i+1]);
	RET sign(area / 2);/*不等式为不等号*/
}
void process(TLine L[],int n,DB d)//压缩d...
{
	int i;
	for(i=0;i<n;++i)
	{
		DB ta = L[i].a + PI * 0.5,tmp = 0.0;
		if(sign(sin(ta))) tmp = d / sin(ta);
		if(sign(tmp)) L[i].d.y += tmp; else L[i].d.x += d * cos(ta);
		//L[i].k.x += d * cos(ta);
	}
}
TLine buf[MAXN];
int main(){
	//freopen("D: \\in.txt","r",stdin);
	int n,cs,i,j,s,t;
	DB area,l,r,mid;
	while (scanf("%d",&n),n){
		for (i = 0,area = 0.0;i < n;i++){
			a[i].IN();
			if (i > 0) area += a[i-1].cross(a[i]);
		}
		area += a[n-1].cross(a[n] = a[0]);
		if (sign(area) > 0) cs = 1,i = 0;else cs = -1,i = n;//判断顺时针(<0) or逆时针
		for (j = 0;j < n;i += cs,j++)L[j] = TLine(a[i+cs]-a[i],a[i]);
		if(!Cut_HP(L,n,cp,Q,s,t)){puts("0.000000");continue;}
		cp[t+1] = cp[s];
		n=0;
		for(i=s;i<=t;++i)L[n] = buf[n] = TLine(cp[i+1]-cp[i],cp[i]),++n;
		/*puts("Before:");
		for(i=0;i<n;++i)cout<<L[i].a<<" vec:("<<L[i].k.x<<','<<L[i].k.y<<")  pnt:("<<L[i].d.x<<','<<L[i].d.y<<')'<<endl;
		process(L,n,1);
		puts("After:");
		for(i=0;i<n;++i)cout<<L[i].a<<" vec:("<<L[i].k.x<<','<<L[i].k.y<<")  pnt:("<<L[i].d.x<<','<<L[i].d.y<<')'<<endl;
		RET 0;*/
		l = 0.0;
		r = 1e6;
		while(sign(l - r) < 0)
		{
			mid = (l+r) * 0.5;
			for(i=0;i<n;++i)L[i] = buf[i];
			process(L,n,mid);
			if(Cut_HP(L,n,cp,Q,s,t))
				l = mid;
			else
				r = mid;
		}
		printf("%.6lf\n",l);
	}
	return 0;
}
