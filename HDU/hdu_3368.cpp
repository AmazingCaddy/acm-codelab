#include<iostream>
using namespace std;
char map[10][10];
int dir[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
int main( )
{
    int i,j,k,t,ii,jj,max,cnt,n=1,cnt1;
    scanf("%d",&t);
    while( t-- )
    {
        for( i=0; i<8; i++ )
            scanf("%s",map[i]);
        max=0;
        for( i=0; i<8; i++ )
        {
            for( j=0; j<8; j++ )
            {
                if( map[i][j]=='*' )
                {
                    cnt=0;
                    for( k=0; k<8; k++ )
                    {
                        ii=i,jj=j;cnt1=0;
                        while( 1 )
                        {
                            ii=ii+dir[k][0];
                            jj=jj+dir[k][1];
                            if( !( ii>=0 && ii<8 && jj>=0 && jj<8 ) )
                            {
                                cnt1=0;
                                break;
                            }
                            //if( !( ii>=0 && ii<8 && jj>=0 && jj<8 ) )break;
                            if( map[ii][jj]=='L' )
                                cnt1++;
                            else if( map[ii][jj]=='*' )
                            {
                                cnt1=0;
                                break;
                            }
                            else if( map[ii][jj]=='D' )break;
                        }
                        cnt+=cnt1;    
                    }
                    if( max<cnt )max=cnt;
                }    
            }
        }
        printf("Case %d: %d\n",n++,max);
    }
    return 0;
}
