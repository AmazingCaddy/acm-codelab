#include <iostream>
#include <cstdio>
using namespace std;
typedef long long Lint;

int main()
{
	Lint n, ans;
	for ( ; ; ) 
	{
		cin >> n;
		if ( n == 0 ) 
		{
			break;
		}
		ans = 111111111111111111LL;
		while ( n % ans != 0 )
		{
			ans /= 10;
		}
		cout << n / ans << endl;
	}
	return 0;
}
