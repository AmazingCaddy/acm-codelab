#include <iostream>

using namespace std;

int main() {
        int n;
        for ( ; ; ) {
                cin >> n;
                if ( n == 0 ) {
                        break;
                }
                cout << n / 2 << endl;
        }
        return 0;
}
