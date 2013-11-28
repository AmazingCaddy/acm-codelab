#include<iostream>
#include<cstring>
using namespace std;
const int maxlen=505;
class HP 
{
public:
	int len,s[maxlen]; 
	HP( ) { ( *this )=0; };
	HP( int inte ) { ( *this )=inte; }; 
	HP( const char *str ) { ( *this )=str; };
	friend ostream& operator<<( ostream &cout, const HP &x );
	HP operator=( int inte ); HP operator=( const char *str );
	HP operator/( const HP &b );int Compare ( const HP &b );
	HP operator-( const HP &b );HP operator%( const HP &b );
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

HP HP::operator-( const HP &b )
{
	int i,j;
	HP c;
	for ( i=1,j=0; i<=len; i++ ) 
	{
		c.s[i]=s[i]-j; 
		if( i<=b.len ) c.s[i]-=b.s[i];
		if( c.s[i]<0 ){ j=1; c.s[i]+=10; } 
		else j=0;
	}
	c.len=len; 
	while ( c.len>1 && !c.s [c.len] ) c.len--;
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

HP HP::operator/( const HP &b )
{
	int i,j; 
	HP d ( 0 ),c;
	for ( i=len; i>0; i-- ) 
	{
		if ( !( d.len==1 && d.s[1]==0) )
		{ 
			for( j=d.len; j>0; j-- ) 
				d.s [j+1]=d.s[j]; 
			++d.len; 
		}
		d.s[1]=s[i]; c.s[i]=0;
		while ( ( j=d.Compare( b ) )>=0 )
		{ d=d-b; c.s[i]++; if ( j==0 ) break; }
	}
	c.len=len; 
	while ( ( c.len>1 ) && ( c.s[c.len]==0) ) c.len--;
	return c;
}

HP HP::operator%( const HP &b )
{
	int i,j;
	HP d( 0 );
	for ( i=len; i>0; i-- )  
	{
		if ( !( d.len==1 && d.s[1]==0 ) )
		{ 
			for( j=d.len; j>0; j-- ) 
				d.s[j+1]=d.s[j]; 
			++d.len; 
		}
		d.s[1]=s[i];
		while ( ( j=d.Compare( b ) )>=0 ){ d=d-b; if( j==0 ) break; }
	}
	return d;
}

int main( )
{
	char a[maxlen],b[maxlen];
	while( scanf("%s%s",a,b) != EOF )
	{
		HP A(a),B(b),C=A%B;
		cout<<A/B;;	
		if( C.len==1 && C.s[1]==0 )
		{
			cout<<endl;
			continue;
		}
		else cout<<" "<<A%B<<endl;
	}
	return 0;
}