#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        long long row, col;
        cin >> row;
        cin >> col;
        long long layer = max(row, col);
        // If layer is odd, start from left end
        // If layer is even, start from right end
        if (layer % 2 == 1) {
            if (layer == col) {
                cout << layer * layer - row + 1 << endl;
            } else {
                cout << (layer - 1) * (layer - 1) + col << endl;
            }
        } else {
            if (layer == col) {
                cout << (layer - 1) * (layer - 1) + row << endl;
            } else {
                cout << layer * layer - col + 1 << endl;
            }
        }
    }
    return 0;
}