#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << n << endl;
    } else if (n < 4) {
        cout << "NO SOLUTION" << endl;
    } else if (n == 4) {
        cout << "3 1 4 2" << endl;
    } else {
        for (int i = 1; i < n + 1; i += 2) {
            cout << i << " ";
        }
        for (int i = 2; i < n + 1; i += 2) {
            cout << i << " ";
        }
    }
    return 0;
}