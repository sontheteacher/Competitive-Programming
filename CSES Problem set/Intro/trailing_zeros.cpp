#include <cmath>
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int power2 = 0;
    int power5 = 0;
    const int max_p2 = (int)log2(n);
    const int max_p5 = (int)(log(n) / log(5));

    for (int i = 1; i <= max_p2; i++) {
        int base = (int) pow(2, i);
        power2 += n / base;
    }
    for (int i = 1; i <= max_p5; i++) {
        int base = (int) pow(5, i);
        power5 += n / base;
    }
    cout << min(power2, power5) << endl;
}