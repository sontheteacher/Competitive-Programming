#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    int res = 1;
    for (int i = 0; i < n; i++) {
        res = (res * 2) % (int) (pow(10, 9) + 7);
    }
    cout << res << endl;
    return 0;
}