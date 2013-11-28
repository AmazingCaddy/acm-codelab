#include <iostream>
#include <string>
using namespace std;

static int pos = -1;
bool WFF( const string& formula, int i )
{
	++pos;
	switch( formula[pos] )
	{
	case 'p':
		return i & 1;
	case 'q':
		return (i >> 1) & 1;
	case 'r':
		return (i >> 2) & 1;
	case 's':
		return (i >> 3) & 1;
	case 't':
		return (i >> 4) & 1;
	case 'N':
		return !WFF( formula, i );
	case 'K':
		return WFF( formula, i ) & WFF( formula, i );
	case 'A':
		return WFF( formula, i ) | WFF( formula, i );
	case 'C':
		return !WFF( formula, i ) | WFF( formula, i );
	case 'E':
		return WFF( formula, i ) == WFF( formula, i );
	}
	return false;
};

bool isTautology( string formula )
{
	for ( int i = 0; i < 32; ++i )
	{
		pos = -1;
		if ( WFF( formula, i ) == false ) return false;;
	}
	return true;
};

int main( int argc, char* argv[] )
{
	string ln;
	while ( cin >> ln && ln[0] != '0' )
	{
		if ( isTautology( ln ) ) cout << "tautology\n";
		else cout << "not\n";
	}
	return 0;
}