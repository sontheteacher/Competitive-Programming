#include <iostream>

int main()
{
    using namespace std;
    long long n;
    cin >> n;
    while (n != 1) {
        cout << n << " ";
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = n * 3 + 1;
        }
    }
    cout << 1 << endl;
    return 0;
}
