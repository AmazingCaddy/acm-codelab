#include<iostream>
#include<map>
#include<string>
using namespace std;
int main()
{
	int n,i;
	map<string,string> m1;
	map<string,string> m2;
	string str1,str2;
	getline(cin,str1);
	while( getline(cin,str2) && str2!="END OF INPUT" )
	{
		m1[str2]=str1;
	}
	getline(cin,str1);
	while( getline(cin,str2) && str2!="END OF INPUT" )
	{
		m2[str2]=str1;
	}
	cin>>n;
	getchar( );
	for( i=0; i<n; i++ )
	{
		getline(cin,str1);
		if( m1.find( str1 )!=m1.end( ) )cout<<m1[str1]<<endl;
		else if( m2.find( str1 )!=m2.end( ) )cout<<m2[str1]<<endl;
		else cout<<"It may appear in A Best!"<<endl;
	}
	return 0;
}

