#include<iostream>
#include<string>
using namespace std;
int main()
{
	int mat[4][4];
	int t,i,j,n,x,y,temp;
	string str;
	scanf("%d",&t);
	while( t-- )
	{
		for( i=0; i<3; i++ )
		{
			for( j=0; j<3; j++ )
			{
				scanf("%d",&mat[i][j]);
				if( !mat[i][j] ){ x=i;y=j;}
			}
		}
		scanf("%d",&n);
		while( n-- )
		{
			cin>>str;
			if( str[0]=='u' && x!=0 )
			{
				temp=mat[x][y];
				mat[x][y]=mat[x-1][y];
				mat[x-1][y]=temp;
				x=x-1;
			}
			if( str[0]=='d' && x!=2 )
			{
				temp=mat[x][y];
				mat[x][y]=mat[x+1][y];
				mat[x+1][y]=temp;
				x=x+1;
			}
			if( str[0]=='l' && y!=0 )
			{
				temp=mat[x][y];
				mat[x][y]=mat[x][y-1];
				mat[x][y-1]=temp;
				y=y-1;
			}
			if( str[0]=='r' && y!=2 )
			{
				temp=mat[x][y];
				mat[x][y]=mat[x][y+1];
				mat[x][y+1]=temp;
				y=y+1;
			}
		}
		for( i=0; i<3; i++ )
		{
			for( j=0; j<3; j++ )
			{
				if( j )printf(" ");
				printf("%d",mat[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}