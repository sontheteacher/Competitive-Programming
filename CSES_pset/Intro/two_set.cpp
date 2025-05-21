#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

void TwoSets(int n) {
    ll total_sum = (1ll * n * (1ll * n + 1)) / 2;
    if (total_sum % 2 == 1) {
        cout << "NO\n";
        return;
    } else {
        cout << "YES\n";
        vector<int> list1, list2;
        vector<int> visited(n + 1, 0);
        ll list1_sum = 0;
        int max_element = n;
        while (list1_sum < total_sum / 2) {
            ll remain_sum = total_sum / 2 - list1_sum;
            if (remain_sum >= max_element) {
                list1.push_back(max_element);
                list1_sum += max_element;
                visited[max_element] = 1;
                max_element--;
            }
            else {
                list1.push_back(remain_sum);
                list1_sum += remain_sum;
                visited[remain_sum] = 1;
            }
        }
        for (int i = 1; i < n + 1; i++) {
            if (visited[i] == 0) {
                list2.push_back(i);
            }
        }

        cout << list1.size() << endl;
        for (int x : list1) {
            cout << x << " ";
        }

        cout << "\n" << list2.size() << endl;
        for (int x : list2) {
            cout << x << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    TwoSets(n);
    return 0;
}