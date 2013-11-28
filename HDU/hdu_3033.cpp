#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

#define MAXN 12
#define MAXM 10010
int price[MAXN][102],value[MAXN][102],cnt[MAXN];
int opt[2][MAXM],N,M,K;

int dp ( )
{
    int i,j,k,tp,tv,res=-1;
    memset(opt[0],-1,sizeof(opt[0]));
    opt[0][0]=0;
    for ( i=1 ; i<=K ; i++ )
    {
		memset(opt[i%2],-1,sizeof(opt[i%2]));
        for ( k=0 ; k<cnt[i] ; k++ )
        {
            for ( j=M ; j>=0 ; j-- )
            {
                tp=j+price[i][k];
                if ( tp>M )
                    continue;
                if ( opt[i%2][j]!=-1 )
                {
                    tv=opt[i%2][j]+value[i][k];
                    if ( tv>opt[i%2][tp] )
                        opt[i%2][tp]=tv;
                }
                if ( opt[(i-1)%2][j]!=-1 )
                {
                    if ((tv=opt[(i-1)%2][j]+value[i][k])>opt[i%2][tp] )
                    {
                        opt[i%2][tp]=tv;
                    }
                }
            }
        }
    }
    for ( i=0 ; i<=M ; i++ )
    {
        if ( opt[K%2][i]>res )
            res=opt[K%2][i];
    }
    return res;
}

void init ( )
{
    int a,b,c,i;
    memset(cnt,0,sizeof(cnt));
    for ( i=0 ; i<N ; i++ )
    {
        scanf("%d%d%d",&a,&b,&c);
//        if ( b>M )
//            continue;
        price[a][cnt[a]]=b;
        value[a][cnt[a]]=c;
        cnt[a]++;
    }
}

int main ( )
{
    while ( scanf("%d%d%d",&N,&M,&K)!=EOF )
    {
        init();
        int res=dp();
        if ( res==-1 )
            puts("Impossible");
        else
            printf("%d\n",res);
    }

} 