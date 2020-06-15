#include <iostream>

using namespace std;
using int64 = long long;

int64 divsum(const int64& n) {
    if (n == 1LL) return 0;
    int64 res = 1;
    for (int64 i=2; i*i<=n; i++) {
        if (n%i == 0) {
            res += i;
            res += (i!=n/i? n/i : 0);
        }
    }
    return res;
}

int main() {
    int64 n;
    cin >> n;

    int64 sum = divsum(n);
    if (sum == n) {
        cout << "Perfect" << endl;
    } else if (sum > n) {
        cout << "Abundant" << endl;
    } else {
        cout << "Deficient" << endl;
    }
}