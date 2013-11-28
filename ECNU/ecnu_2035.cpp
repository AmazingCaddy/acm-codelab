#include<iostream>
using namespace std;
unsigned int c[33];
int main( )
{
	int a,b,x,y,i,ans,t;
	char ch;
	c[0]=1;
	for( i=1; i<33; i++ )
		c[i]=c[i-1]*2;
	while( scanf("%d%d %c",&a,&b,&ch) != EOF )
	{
		t=0;
		switch(ch)
		{
		case '^':
			ans=1;break;
		case '|':  
			for( i=1; i<32; i++ )
			{
				x=a&1;
				y=b&1;
				if( x==1 && y==0 )break;
				a=a>>1;
				b=b>>1;
				t=t+x;
			}
			if( i==32 ) ans=c[t];
			else ans=0;
			break;
		case '&':
			for( i=0; i<32; i++ )
			{
				x=a&1;
				y=b&1;
				if( x==0 && y==1 ) break; 
				a=a>>1;
				b=b>>1;
				t=t+!x;
			}
			if( i==32 )ans=c[t];
			else ans=0;
			break;
		}
		printf("%d\n",ans);
	}
	return 0;
}
