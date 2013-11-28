#include<iostream>
#include<cstring>
using namespace std;
int main( )
{
	char a[20],b[20];
	int lena,lenb;
	int i,j;
	scanf("%s%s",a,b);
	lena=strlen(a);
	lenb=strlen(b);
	int sum=0;
	for( i=0; i<lena; i++ )
		for( j=0; j<lenb; j++ )
			sum+=(a[i]-'0')*(b[j]-'0');
	printf("%d\n",sum);
	return 0;
}