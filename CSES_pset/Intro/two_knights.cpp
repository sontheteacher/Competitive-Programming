#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n;
    cin >> n;
    for (int k = 1; k <= n; k++) {
        if (k == 1) {
            cout << 0 << endl;
        } else if (k == 2){ 
            cout << 6 << endl;
        } else {
            long size = pow(k, 2);
            long res = (size * (size - 1) / 2) - 4 * (k - 2) * (k - 1);
            cout << res << endl;
        }
    }
    return 0;
}