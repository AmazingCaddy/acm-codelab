#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<string>
using namespace std;

map< string, int > mat;
const int maxn = 40;
double a[maxn][maxn], b[maxn][maxn];

bool Floyd( int n )
{
    int i, j, k;
    for( i = 1; i <= n; i++ )
        for( j = 1; j <= n; j++ )
            b[i][j] = a[i][j];
            
    for( k = 1; k <= n; k++ )
        for( i = 1; i <= n; i++ )
            for( j = 1; j <= n; j++ )
                if( b[i][j] < b[i][k] * b[k][j] )
                    b[i][j] = b[i][k] * b[k][j];
    for( i = 1; i <= n; i++ )
        if( b[i][i] > 1 )
            return true;
    return false;        
}

int main( )
{
    int n, m, i, k = 1;
    double x;
    string str, str1, str2;
    while( scanf("%d",&n) && n )
    {
        mat.clear( );
        for( i = 1; i <= n; i++ )
        {
            cin >> str;
            //cout << str << endl;
            mat[str] = i;
            //printf("%d\n",i);
        }
        scanf("%d",&m);
        //printf("%d\n",m);
        
        for( i = 0; i < m; i++ )
        {
            cin >> str1 >> x >> str2;
            a[mat[str1]][mat[str2]] = x;
        }
        if( Floyd( n ) ) printf("Case %d: Yes\n",k++);
        else printf("Case %d: No\n", k++);
    }
}


