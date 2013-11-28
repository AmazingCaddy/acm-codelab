#include<iostream>
#include<string>
#define MAXN 6
using namespace std;
char mat[MAXN][MAXN];
bool letters[26];

void inti_key( const string & str )
{
	int i,j;
	memset( letters, false, sizeof(letters) );
	for( j=i=0; i<str.size( ); i++ )
		if( str[i] != ' ' && !letters[str[i]-'a'] )
			mat[j/5][j%5]=str[i]-32,j++,letters[str[i]-'a']=true;
	for( i=0; i<26; i++ )
		if( !letters[i] && i!='q'-'a' )
			mat[j/5][j%5]=i+'A',j++,letters[i]=true;
}

string encryption( string & text )
{
	int i,j,k,fi,fj,si,sj;
	string str1,str;
	for( j=i=0; i<text.size( ); i++ )
		if( text[i]!=' ' )str1+=text[i];
	j=str1.size( );
	for( i=0; i*2<j; i++ )
		if( str1[i*2]==str1[2*i+1] )str1.insert( 2*i+1, "x" ),j++;
	if( str1.size( )%2==1 )str1+='x';
	text=str1;
	bool flag=true;
	for( i=0; i<text.size( )-1; i++ )
	{
		if( text[i] == ' ' )continue;
		if( text[i] != ' ' )
		{
			if( flag )
				for( j=0; j<5; j++ )
					for( k=0; k<5; k++ )
						if( mat[j][k]==text[i]-32 )fi=j,fj=k;
			if( !flag )
				for( j=0; j<5; j++ )
					for( k=0; k<5; k++ )
						if( mat[j][k]==text[i]-32 )si=j,sj=k;
			flag=!flag;
		}
		if( flag )
		{
			if( fi==si )str=str+mat[fi][(fj+1)%5]+mat[fi][(sj+1)%5];
			else if( fj==sj )str=str+mat[(fi+1)%5][fj]+mat[(si+1)%5][fj];
			else str=str+mat[fi][sj]+mat[si][fj];
		}
	}
	if( !flag )
	{
		for( j=0; j<5; j++ )
			for( k=0; k<5; k++ )
				if( mat[j][k]==text[i]-32 )si=j,sj=k;
		if( fi==si )str=str+mat[fi][(fj+1)%5]+mat[fi][(sj+1)%5];
		else if( fj==sj )str=str+mat[(fi+1)%5][fj]+mat[(si+1)%5][fj];
		else str=str+mat[fi][sj]+mat[si][fj];
	}
	if( flag )
	{
		for( j=0; j<5; j++ )
			for( k=0; k<5; k++ )
				if( mat[j][k]==text[i]-32 )fi=j,fj=k;
		for( j=0; j<5; j++ )
			for( k=0; k<5; k++ )
				if( mat[j][k]=='X' )si=j,sj=k;
		if( fi==si )str=str+mat[fi][(fj+1)%5]+mat[fi][(sj+1)%5];
		else if( fj==sj )str=str+mat[(fi+1)%5][fj]+mat[(si+1)%5][fj];
		else str=str+mat[fi][sj]+mat[si][fj];
	}
	return str;
}

int main( )
{
	string key,text,ans;
	int i,j;
	while( getline( cin, key ) )
	{
		inti_key( key );
		getline( cin, text );
		ans=encryption( text );
		cout<<ans<<endl;
	}
	return 0;
}
		