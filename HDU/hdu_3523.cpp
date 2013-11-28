////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 546711990
////Nickname: AmazingCaddy
////Run ID: 
////Submit time: 2010-08-15 20:34:21
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3523
////Problem Title: 
////Run result: Accept
////Run time:250MS
////Run memory:280KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

using namespace std;




#define MAXN 110
#define inf 1000000000
#define _clr(x) memset(x,0xff,sizeof(int)*n)
int bufa[ MAXN ], bufb[ MAXN ];

int kuhn_munkras(int m,int n,int mat[][MAXN],int* match1,int* match2){
	int s[MAXN],t[MAXN],l1[MAXN],l2[MAXN],p,q,ret=0,i,j,k;
	for (i=0;i<m;i++)
		for (l1[i]=-inf,j=0;j<n;j++)
			l1[i]=mat[i][j]>l1[i]?mat[i][j]:l1[i];
	for (i=0;i<n;l2[i++]=0);
	for (_clr(match1),_clr(match2),i=0;i<m;i++){
		for (_clr(t),s[p=q=0]=i;p<=q&&match1[i]<0;p++)
			for (k=s[p],j=0;j<n&&match1[i]<0;j++)
				if (l1[k]+l2[j]==mat[k][j]&&t[j]<0){
					s[++q]=match2[j],t[j]=k;
					if (s[q]<0)
						for (p=j;p>=0;j=p)
							match2[j]=k=t[j],p=match1[k],match1[k]=j;
				}
		if (match1[i]<0){
			for (i--,p=inf,k=0;k<=q;k++)
				for (j=0;j<n;j++)
					if (t[j]<0&&l1[s[k]]+l2[j]-mat[s[k]][j]<p)
						p=l1[s[k]]+l2[j]-mat[s[k]][j];
			for (j=0;j<n;l2[j]+=t[j]<0?0:p,j++);
			for (k=0;k<=q;l1[s[k++]]-=p);
		}
	}
	for (i=0;i<m;i++)
		ret+=mat[i][match1[i]];
	return ret;
}





const int L = MAXN;

int n, m, a[ L ][ L ], w[ L ][ L ];

int main() {
        int totCase, curCase, i, j, k, ans;
        scanf( "%d", &totCase );
        for ( curCase = 1; curCase <= totCase; ++curCase ) {
                scanf( "%d%d", &n, &m );
                for ( i = 0; i < m; ++i ) {
                        for ( j = 0; j < n; ++j ) {
                                scanf( "%d", &(a[ i ][ j ]) );
                        }
                }
                for ( i = 0; i < n; ++i ) {
                        for ( j = 0; j < n; ++j ) {
                                w[ i ][ j ] = 0;
                                for ( k = 0; k < m; ++k ) {
                                        w[ i ][ j ] -= abs( i + 1 - a[ k ][ j ] );
                                }
                        }
                }
                ans = -kuhn_munkras( n, n, w, bufa, bufb );
                printf( "Case #%d: %d\n", curCase, ans );
        }
        return 0;
}
