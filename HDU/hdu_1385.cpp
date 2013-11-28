#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int maxn = 50;
const int inf = 1000000000;
int a[maxn][maxn], b[maxn][maxn], path[maxn][maxn];
int c[maxn];

void Floyd( int n )
{
    int i, j, k;
    for( i = 1; i <= n; i++ )
        for( j = 1; j <= n; j++ )
            b[i][j] = a[i][j], path[i][j] = j;

    for( k = 1; k <= n; k++ )
    {
        for( i = 1; i <= n; i++ )
        {
            for( j = 1; j <= n; j++ )
            {   
                int t = b[i][k] + b[k][j] + c[k];
                if( t < b[i][j] )
                {
                    b[i][j] = t;
                    path[i][j] = path[i][k];
                }
                else if( b[i][j] == t && path[i][k] < path[i][j] )
                    path[i][j] = path[i][k];
             }
         }
    }    
}

void print_path( int i, int j )
{
    int k;
    k = path[i][j];
    if( k == 0 )return;
    print_path( i, k );
    printf("%d-->", k);
    print_path( k, j );
}

void solve( int n )
{   
    int i, j, p, q, k;
    for( i = 1; i <= n; i++ )
        for( j = 1; j <= n; j++ )
        {
            scanf("%d",&a[i][j]);
            if( a[i][j] == -1 ) a[i][j] = inf;
        }    
    for( i = 1; i <= n; i++ )
        scanf("%d",&c[i]);
    /*    
    for( i = 1; i <= n; i++ )
        for( j = 1; j <= n; j++ )
            if( a[i][j] < inf )
               a[i][j] += c[j]; 
    */
    Floyd( n );  
    /*
    for( i = 1; i <= n; i++ )
    {
        for( j = 1; j <= n; j++ )
            printf("%d ",b[i][j]);
        printf("\n");   
    }
    */
    while( 1 )
    {
        scanf("%d%d",&p,&q);
        if( p == -1 && q == -1 ) break;
        /*
        if( p != q )
        {
            printf("From %d to %d :\n",p,q);
            printf("Path: %d-->",p);
            print_path( p, q );
            printf("%d\n",q);
            printf("Tatol cost : %d\n\n",b[p][q]);
        }
        else
        {
            printf("From %d to %d :\n",p,q);  
            printf("Path: %d\n",p);
            printf("Total cost : %d\n\n",0);
        }
        */
        
        printf("From %d to %d :\n",p,q);
        printf("Path: %d",p);
        k = p;
        while( k != q )
        {
            printf("-->%d",path[k][q]);
            k = path[k][q];
        }
        printf("\nTotal cost : %d\n\n",b[p][q]);
        
    }
}

int main( )
{
    int n;
    while( scanf("%d",&n) && n )
    {
        solve( n );
    }    
}

/* 
4
0 1 -1 2
1 0 4 -1
-1 4 0 3
2 -1 3 0
4 1 3 2
1 3
-1 -1
0

*/

