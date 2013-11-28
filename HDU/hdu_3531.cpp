////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 546711990
////Nickname: AmazingCaddy
////Run ID: 
////Submit time: 2010-08-22 12:52:04
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3531
////Problem Title: 
////Run result: Accept
////Run time:406MS
////Run memory:5128KB
//////////////////System Comment End//////////////////
#include<cstring>
#include<string>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<cmath>
#include<stdlib.h>
#include<time.h>
#include<algorithm>
#include<iostream>
#include<stdio.h>
#define N 1005
#define M 505
#define mod 9997
#define R 2
using namespace std;
int G[N][N];
int F[M][M];
int x[N];
int powR[M + 1];
bool check(int x, int y, int m){
    for(int i = x - m + 1, ii = 1; i <= x; ++i, ++ii)
        for(int j = y - m + 1, jj = 1; j <= y; ++j, ++jj)
            if(G[i][j] != F[ii][jj])
                return false;
    return true;
}
int main(){
    //freopen("F_in.txt", "r", stdin);
    //freopen("F_out.txt", "w", stdout);
    //int now = clock();
    int n, m;
    int dst, ans;
    bool flag;
    powR[0] = 1;
    for(int i = 1; i <= M; ++i)
        powR[i] = (powR[i - 1] * R) % mod;
   
    while(scanf("%d %d", &n, &m) != EOF){
        
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                scanf("%d", &G[i][j]);
        for(int i = 1; i <= m; ++i)
            for(int j = 1; j <= m; ++j)
                scanf("%d", &F[i][j]);
        flag = false;
        dst = 0;
        for(int i = 1; i <= m; ++i){
            x[i] = 0;
            for(int j = 1; j <= m; ++j)
                x[i] = (x[i] * R + F[j][i]) % mod;
            dst = (dst * R + x[i]) % mod;
        }   
        x[0] = 0;
        for(int i = 1; i <= n; ++i){
            x[i] = 0;
            for(int j = 1; j <= m; ++j)
                x[i] = (x[i] * R + G[j][i]) % mod;
        }
        for(int i = m; i <= n && !flag; ++i){
            ans = 0;
            for(int j = 1; j <= n; ++j){
                
                if(j <= m - 1)
                    ans = (ans * R + x[j]) % mod;
                else{
                    ans = (((ans - x[j - m] * powR[m - 1]) * R) + x[j]) % mod;
                    if((ans + mod) % mod == dst){
                        if(check(i, j, m)){
                            flag = true;
                            break;
                        }
                    }
                }
            }
            if(i < n)
                for(int j = 1; j <= n; ++j)
                    x[j] = ((x[j] - G[i - m + 1][j] * powR[m - 1]) * R + G[i + 1][j]) % mod;
        }
        if(flag)
            printf("Yes\n");
        else printf("No\n"); 
        
    }
    //printf("%dms\n", clock() - now);
}
