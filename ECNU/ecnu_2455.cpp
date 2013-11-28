#include <iostream>
#define pi 3.14159265358979323846
#define max(x,y)x>y?x:y
#define min(x,y)x<y?x:y
using namespace std;

int main()
{
	double w,h,t1,t2,r1,r2,ans;
	while(scanf("%lf%lf",&w,&h)!=EOF&&(w||h))
	{
		r1=w/2/pi;
		t1=pi*r1*r1*(h-2*r1);
		r2=min(w/2,h/2/(1+pi));
		t2=r2*r2*w*pi;
		ans=max(t1,t2);
		printf("%.3lf\n",ans);
	}
	return 0;
}