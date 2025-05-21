#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long> input(N);
    long total = 0;
    for (int i = 0; i < N; i++) {
        cin >> input[i];
        total += input[i];
    }

    uint64_t res = total * total;

    for (int i : input) {
        res -= i * i;
    }
    res /= 2;
    cout << res << endl;
}