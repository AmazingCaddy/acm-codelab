#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str;
	getline(cin,str);
	for( string::size_type i=0; i<str.size(); i++ )
	{
		if(str[i]>='a'&&str[i]<='z')str[i]-=32;
	}
	cout<<str<<endl;
	return 0;
}