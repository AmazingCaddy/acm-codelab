/*
    author: AmazingCaddy
    time: 17/05/2011 21:15:31 
*/
#include <iostream>
#include <complex>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int maxn = 10004;
const int inf = 1000000000;
const double eps = 1e-8;
const double pi = acos( -1.0 );

/*
For p use the value: 3.1415927.
There are 5280 feet in a mile.
There are 12 inches in a foot.
There are 60 minutes in an hour.
There are 60 seconds in a minute.
There are 201.168 meters in a furlong.
*/
int main( int ac, char * av[ ] )
{
	double d, n, s;
	int t = 1;
	while( scanf( "%lf%lf%lf", &d, &n, &s ) && n != 0 )
	{
		double ans1 = d * pi * n / 12 / 5280;
		double ans2 = ans1 / s * 3600;
		printf( "Trip #%d: %.2lf %.2lf\n", t++, ans1, ans2 );
	}
	return 0;
}
