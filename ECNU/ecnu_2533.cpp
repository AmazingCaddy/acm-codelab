#include <stdio.h> 
int n;
int main() 
{ 
	double t,x,y,low=0,high=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%lf",&t);
		if (t<low) low=low-t;
		else if (t>high) low=t-high;
		else low=0;
		high=high+t;
	}
	scanf("%lf%lf",&x,&y);
	if (low*low<=x*x+y*y&&x*x+y*y<=high*high) printf("Yes\n");else printf("No\n");

	return 0;
}