////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 546711990
////Nickname: AmazingCaddy
////Run ID: 
////Submit time: 2010-03-19 13:39:36
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1002
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:312KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstring>
using namespace std;
const int maxlen=1003;
class HP 
{
public:
	int len,s[maxlen]; 
	HP( ) { ( *this )=0; };
	HP( int inte ) { ( *this )=inte; }; 
	HP( const char *str ) { ( *this )=str; };
	friend ostream& operator<<( ostream &cout, const HP &x );
	HP operator=( int inte ); HP operator=( const char *str );
	HP operator+( const HP &b );
	HP operator-( const HP &b ); 
	int Compare ( const HP &b );
};

ostream& operator<<( ostream &cout, const HP &x )
{
	for ( int i=x.len; i>=1; i-- ) 
		cout<<x.s[i];
	return cout; 
}

HP HP::operator=( const char *str )
{
	len=strlen( str );
	for ( int i=1; i<=len; i++ ) 
		s[i]=str[len-i]-'0';
	return *this;
}

HP HP::operator=( int inte )
{
	if ( inte ==0) { len=1; s[1]=0; return ( *this ); };
	for ( len=0; inte>0; ){ s[++len]=inte%10; inte/=10; };
	return ( *this );
}

HP HP::operator+( const HP &b )
{
	int i; 
	HP c; c.s[1]=0;
	for ( i=1; i<=len || i<=b.len || c.s[i]; i++ )
	{
		if ( i<=len ) c.s[i]+=s[i];
		if ( i<=b.len ) c.s[i]+=b.s[i];
		c.s[i+1]=c.s[i]/10; c.s[i]%=10;
	}
	c.len=i-1; if( c.len==0 ) c.len=1;
	return c ;
}

int HP::Compare( const HP &y )
{
	if ( len>y.len ) return 1;
	if ( len<y.len ) return -1;
	int i=len ;
	while ( ( i >1 ) && ( s[i]==y.s[i] ) ) i--;
	return s[i]-y.s[i];
}

int main( )
{
	int n,i;
	char a[maxlen],b[maxlen];
	HP A,B;
	
	scanf("%d",&n);
	for( i=1; i<=n; i++ )
	{
		if( i != 1 )cout<<endl;
		cin>>a>>b;
		A=a,B=b;
		cout<<"Case "<<i<<":"<<endl;
		cout<<A<<" + "<<B<<" = "<<A+B<<endl;
	}
	return 0;
}