/*
	author: AmazingCaddy
	time:	
	solve:	
*/
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <complex>
#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;

const int maxn = 105;

char buf[ maxn ];
int main(int argc, char *argv[]){
	int cnt;
	while (scanf("%s", buf) != EOF) {
		int len = strlen(buf);
		int sum = 0, cnt = 0;
		int flag = 1, i = 0;
		char ch;
		while (buf[ i ] != '=') {
			int t = 0;
			while ('0' <= buf[ i ] && buf[ i ] <= '9') {
				t = t * 10 + buf[ i ] - '0';
				i++;
			}
			if ('a' <= buf[ i ] && buf[ i ] <= 'z') {
				ch = buf[ i ];
				if (t == 0) {
					t = 1;
				}
				i++;
				cnt += flag * t;
			} else {
				sum -= flag * t;
			}
			if (buf[ i ] == '+') {
				flag = 1;
				i++;
			} else if (buf[ i ] == '-') {
				flag = -1;
				i++;
			}
		}
		i++;
		flag = 1;
		while (buf[ i ]) {
			int t = 0;
			while ('0' <= buf[ i ] && buf[ i ] <= '9') {
				t = t * 10 + buf[ i ] - '0';
				i++;
			}
			if ('a' <= buf[ i ] && buf[ i ] <= 'z') {
				ch = buf[ i ];
				if (t == 0) {
					t = 1;
				}
				i++;
				cnt -= flag * t;
			} else {
				sum += flag * t;
			}
			if (buf[ i ] == '+') {
				flag = 1;
				i++;
			} else if (buf[ i ] == '-') {
				flag = -1;
				i++;
			}
		}
		printf("%c=%.3lf\n", ch, sum*1.0/cnt);
	}
	return 0;
}
