#include<iostream>
using namespace std;
int prime[34000];
int main()
{
	int i,j;	
	for( i=2; i<=34000; i++ )
		prime[i]=i;
	for( i=2; i<=185; i++ )
	{
		if( prime[i]==i )
			for( j=i*i+i; j<=34000; j+=i )
				prime[j]=0;
		for( j=i*i; j<=34000; j*=i )
			prime[j]=prime[i];
	}
	for( i=)