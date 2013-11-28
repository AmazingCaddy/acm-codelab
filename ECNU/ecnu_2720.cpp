#include<iostream>
#include<string>
#define MAXN 100
using namespace std;
int main()
{
	string str,str1,s[MAXN],t[MAXN];
	int i,k,j,len,len1;
	while( getline( cin,str ) )
	{
		str1="";
		for( i=0; i<str.size( ); i++ )
		{
			if( str[i]==' ' )break;
			else str1+=str[i];
		}
		for( k=0; k<MAXN; k++ )
			s[k]="";
		for( k=0,j=i+1; j<str.size( ) && str[j] != ';'; j++ )
		{
			if( str[j]!=',' )s[k]+=str[j];
			else
			{
				k++;
				j++;
				continue;
			}
		}
		len=k+1;
		for( i=0; i<len; i++ )
		{
			t[i]=str1;
			len1=s[i].size();
			for( j=len1-1; j>=0; j-- )
			{
				if( ! ( s[i][j]<'A' || s[i][j]>'Z' && s[i][j]<'a' || s[i][j]>'z' ) )break;
				else if( s[i][j] !='[' && s[i][j] != ']' )
					t[i]+=s[i][j];
				else t[i]+="[]",j--;
			}
			t[i]+=' ';
			for( k=0; k<=j; k++ )
				t[i]+=s[i][k];
			t[i]+=';';
		}
		for( i=0; i<len; i++ )
			cout<<t[i]<<endl;
	}
	return 0;
}