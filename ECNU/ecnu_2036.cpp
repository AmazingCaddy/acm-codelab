#include<iostream>
#define MAXN 52
using namespace std;
int a[MAXN][MAXN];
int n,m;
void turn_left( int k )
{
	int i,j;
	switch(k)
	{
	case 0: 
		for( i=0; i<n; i++ )
		{
			for( j=0; j<m; j++ )
			{
				if( j != 0 )printf(" ");
				printf("%d",a[i][j]);
			}
			printf("\n");
		}
		break;
	case 1: 
		for( i=m-1; i>=0; i-- )
		{
			for( j=0; j<n; j++ )
			{
				if( j != 0 )printf(" ");
				printf("%d",a[j][i]);
			}
			printf("\n");
		}
		break;
	case 2:
		for( i=n-1; i>=0; i-- )
		{
			for( j=m-1; j>=0; j-- )
			{
				if( j != m-1 )printf(" ");
				printf("%d",a[i][j]);
			}
			printf("\n");
		}
		break;
	case 3: 
		for( i=0; i<m; i++ )
		{
			for( j=n-1; j>=0; j-- )
			{
				if( j != n-1 )printf(" ");
				printf("%d",a[j][i]);
			}
			printf("\n");
		}
		break;
	}
}

int main( )
{
	int i,j,op,num,x;
	char ch;
	//freopen("out.txt","w",stdout);
	while( scanf("%d%d",&n,&m) != EOF )
	{
		for( i=0; i<n; i++ )
			for( j=0; j<m; j++ )
				scanf("%d",&a[i][j]);
		//scanf("%d",&op);
		//getchar( );
		cin>>op;
		num=0;
		for( i=0; i<op; i++ )
		{
			//scanf("%c",&ch);
			cin>>ch;
			if( ch=='O' )
			{
				turn_left( num );
				//getchar( );
			}
			else 
			{
				cin>>x;
				//scanf("%d",&x);
				//getchar( );
				if( ch=='L' ) num=num+x%4;
				else if( ch=='R' ) num=num-x%4;
				num=((num%4)+4)%4;
			}
		}
	}
	return 0;
}