#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <complex>
#include <queue>
using namespace std;

const int maxn = 1003;
const double eps = 1e-8;
const double pi = acos( -1.0 );

int main(int argc, char *argv[])
{
	int R, H;
	while( scanf("%d%d",&R,&H) != EOF )
	{
		double ans = 2 * pi * H * R * R, tmp;
		if( 2 * R < H )
		{
			tmp = 2.0 / 3 * R * R * R;
		}
		else
		{
			double h = H / 2.0;
			double S = sqrt( R * R - h * h );
			tmp = S * h * h + 2.0 / 3 * R * R * R - R * R * S + S * S * S / 3 ;
		}
		printf("%.4lf\n",ans - tmp*8);
	}
	return 0;
}
