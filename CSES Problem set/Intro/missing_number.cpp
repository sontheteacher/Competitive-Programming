#include <iostream>
using namespace std;

int main(){
    long long n;
    long sum = 0;
    int x;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        cin >> x;
        sum += x;
    }
    cout << (n * (n + 1) / 2 - sum) << endl;
}