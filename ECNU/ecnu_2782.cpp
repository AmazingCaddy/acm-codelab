#include<iostream>
#include<string>
#include<map>
using namespace std;
int main( )
{
	int n;
	string str;
	map<string,string> m;
	m["E"]="Excellent";
	m["C"]="Cheer";
	m["N"]="Nice";
	m["U"]="Ultimate";
	m["Impossible"]="I'm possible";
	m["ACM"]="Accept More";
	scanf("%d",&n);
	while( n-- )
	{
		cin>>str;
		cout<<m[str]<<endl;
	}
	return 0;
}