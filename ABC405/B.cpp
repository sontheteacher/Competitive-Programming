#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N;
    cin >> M;
    vector<int> counter(M + 1);
    vector<int> input(N);
    for (int i = 0; i < N; i++) {
        int curr;
        cin >> curr;
        counter[curr]++;
        input[i] = curr;
    }

    for (int i = 1; i < M + 1; ++i) {
        if (counter[i] == 0) {
            cout << 0 << endl;
            return 0;
        }
    }

    int res = 0;

    for (auto it = input.rbegin(); it != input.rend(); ++it) {
        auto curr = *it;
        --counter[curr];
        res++;
        if (counter[curr] == 0) {
            cout << res << endl;
            return 0;
        }
    }
    return 0;
}