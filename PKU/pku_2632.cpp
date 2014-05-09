//  上 W，下 E，右 N，左 S；
//  坐标上小下大，左小右大
//  
#include <iostream>
#define F(i,a,b) for (int i=1;i<=b;i++)
using namespace std;
int map[102][102], nr, ni, posx[102], posy[102], d[102],
move[4][2]={ {0,1}, {1,0}, {0,-1}, {-1,0} };

int dir( char ch )
{
	switch (ch)
	{
	case 'N': return 0;
	case 'E': return 1;
	case 'S': return 2;
	case 'W': return 3;
	}
}
void init( int c, int r )
{
	F( i, 1, r )
	{
		F( j, 1, c )
			map[j][i]=0;
	}
	F( i, 1, c )
		map[i][0]=map[i][r+1]=-1;
	F( i, 1, r )
		map[0][i]=map[c+1][i]=-1;
}
int main( )
{
	int T, A, B;
	bool done;
	cin >> T;
	F( i, 1, T )
	{
		cin >> A >> B;
		init( A, B );
		cin >> nr >> ni;
		int x, y;
		char ch;
		F( j, 1, nr )
		{
			cin >> x >> y >> ch;
			map[x][y]=j;
			posx[j]=x;
			posy[j]=y;
			d[j]=dir(ch);
		}
		done=false;
		F( j, 1, ni )
		{
			cin >> x >> ch >> y;
			if ( done ) continue;
			if ( ch=='F' )
			{
				for( int k=1;k<=y && !done; k++ )
				{
					if( map[posx[x]+move[d[x]][0]][posy[x]+move[d[x]][1]]==0 )
					{
						map[posx[x]][posy[x]]=0;
						posx[x]+=move[d[x]][0];
						posy[x]+=move[d[x]][1];
						map[posx[x]][posy[x]]=x;
					}
					else if( map[posx[x]+move[d[x]][0]][posy[x]+move[d[x]][1]]==-1 )
					{
						cout<<"Robot "<<x<<" crashes into the wall\n";
						done=true;
						//break;
					}
					else
					{
						cout<<"Robot "<<x<<" crashes into robot "
							<<map[posx[x]+move[d[x]][0]][posy[x]+move[d[x]][1]]<<endl;
						done=true;
						//break;
					}
				}
			}
			else if( ch=='L' )
			{
				y=y%4;
				F( j, 1, y )
				{
					if ( d[x]==0 ) d[x]=4;
					d[x]=(d[x]-1)%4;
				}
			}
			else if( ch=='R' )
			{
				y=y%4;
				F( j, 1, y )
					d[x]=(d[x]+1)%4;
			}
		}
		if ( !done ) cout << "OK\n";
	}
	return 0;
}