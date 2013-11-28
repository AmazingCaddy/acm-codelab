#include<iostream>
#define N 100
using namespace std;
int main( )
{
	int i,temp,t,n,m,sum,p,q,k,val,max,min;
	int a[N];
	scanf("%d",&t);
	while( t-- )
	{
		scanf("%d%d",&m,&n);
		sum=0;
		for( i=0; i<m; i++ )
		{
			scanf("%d",&a[i]);
			sum+=a[i];	
		}
		p=sum/n;q=sum;min=sum;
		while( p<=q )
		{
			temp=n;
			k=(p+q)/2;
			max=0;val=0;
			for( i=0; i<m; i++ )
			{
				if( val+a[i]<=k )
				{
					val+=a[i];	
					if( val>max )max=val;
				}
				else 
				{
					val=a[i];
					temp--;
					if( val>max )max=val;
				}
			}
			if( temp>0 )
			{
				q=k-1;
				if( max<min )min=max;
			}
			else p=k+1;	
		}
		printf("%d\n",min);
	}
	return 0;
}