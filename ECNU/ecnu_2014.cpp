#include<iostream>
#include<cstring>
using namespace std;
const int maxlen=100;
class HP 
{
public:
	int len,s[maxlen]; 
	HP( ) { ( *this )=0; };
	HP( int inte ) { ( *this )=inte; }; 
	HP( const char *str ) { ( *this )=str; };
	friend ostream& operator<<( ostream &cout, const HP &x );
	HP operator=( int inte ); HP operator=( const char *str );
	HP operator*( const HP &b );
};

ostream& operator<<( ostream &cout, const HP &x )
{
	for ( int i=x.len; i>=1; i-- ) 
		cout<<x.s[i];
	return cout; 
}

HP HP::operator=( int inte )
{
	if ( inte ==0) { len=1; s[1]=0; return ( *this ); };
	for ( len=0; inte>0; ){ s[++len]=inte%10; inte/=10; };
	return ( *this );
}

HP HP::operator*( const HP &b )
{
	int i,j;
	HP c; 
	c.len=len+b.len;
	for ( i=1; i<=c.len; i++ ) c.s[i]=0;
	for ( i=1; i<=len; i++ ) for ( j=1; j<=b.len; j++ ) c.s[i+j-1]+=s[i]*b.s[j];
	for ( i=1; i<c.len; i++ ) { c.s[i+1]+=c.s[i]/10; c.s[i]%=10; }
	while ( c.s[i] ) { c.s[i+1]=c.s[i]/10; c.s[i]%=10; i++; }
	while ( i>1 && !c.s[i] )i--; c.len=i;
	return c;
}

int main( ) 
{
	int k,i;
	HP hp[52];
	hp[1]=36;
	for( i=2; i<=50; i++ )
		hp[i]=hp[i-1]*55;
	while( scanf("%d",&k) != EOF )
	{
		cout<<hp[k]<<endl;
	}
}