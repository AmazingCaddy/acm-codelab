#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;

const int maxn = 1003;

int main( )
{
	char str[maxn];
	int num[maxn];
	int t, len, i, j, sum;
	scanf("%d",&t);
	while( t-- )
	{
		scanf("%s",str);
		len = strlen( str );
		for( i = 0; i < len; i++ )
			num[len-i-1] = str[i] - '0';
		num[len] = 0;
		sum = num[0];
		for( i = 1; i <=len; i++ )
		{
			if( sum > 0 && num[i] != 9 )
			{
				sum--;
				for( num[i]++, j = 0; j < i; j++ )
				{
					if( sum > 9 )num[j] = 9, sum -= 9;
					else num[j] = sum , sum = 0;
				}
				break;
			}
			else sum += num[i];
		}
		if( num[len] == 1 )
		{
			for( i = len; i >= 0; i-- )
				printf("%d",num[i]);
			printf("\n");
		}
		else 
		{
			for( i = len - 1; i >= 0; i-- )
				printf("%d",num[i]);
			printf("\n");
		}
	}
	return 0;
}