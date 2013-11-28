/*
	
*/
#include <set>
#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>

using namespace std;

const int N = 111111;

int n, m, x[N], y[N], backupXCnt, backupX[N], backupYCnt, backupY[N];
set<int> hashX[N], hashY[N];

int findX(int x){
    int iter = lower_bound(backupX, backupX + backupXCnt, x) - backupX;
    if(iter < backupXCnt and backupX[iter] == x){
        return iter;
    }
    return -1;
}

int findY(int y){
    int iter = lower_bound(backupY, backupY + backupYCnt, y) - backupY;
    if(iter < backupYCnt and backupY[iter] == y){
        return iter;
    }
    return -1;
}

int main(){
    while(scanf("%d%d", &n, &m) == 2 and n + m){
        for(int i = 0; i < n; ++ i){
            scanf("%d%d", x + i, y + i);
        }
        for(int i = 0; i < n; ++ i){
            backupX[i] = x[i];
        }
        sort(backupX, backupX + n);
        backupXCnt = unique(backupX, backupX + n) - backupX;
        for(int i = 0; i < n; ++ i){
            backupY[i] = y[i];
        }
        sort(backupY, backupY + n);
        backupYCnt = unique(backupY, backupY + n) - backupY;
        for(int i = 0; i < n; ++ i){
            hashX[i].clear();
            hashY[i].clear();
        }
        for(int i = 0; i < n; ++ i){
            hashX[findX(x[i])].insert(i);
            hashY[findY(y[i])].insert(i);
        }
        while(m --){
            int o, a;
            scanf("%d%d", &o, &a);
            if(o == 0){
                int temp = findX(a);
                if(temp == -1){
                    printf("0\n");
                }else{
                    printf("%d\n", (int)hashX[temp].size());
                    for(set<int>::iterator iter = hashX[temp].begin(); iter != hashX[temp].end(); ++ iter){
                        hashY[findY(y[*iter])].erase(*iter);
                    }
                    hashX[temp].clear();
                }
            }else{
                int temp = findY(a);
                if(temp == -1){
                    printf("0\n");
                }else{
                    printf("%d\n", (int)hashY[temp].size());
                    for(set<int>::iterator iter = hashY[temp].begin(); iter != hashY[temp].end(); ++ iter){
                        hashX[findX(x[*iter])].erase(*iter);
                    }
                    hashY[temp].clear();
                }
            }
        }
        printf("\n");
    }
    return 0;
}
