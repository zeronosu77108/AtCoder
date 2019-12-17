#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <numeric>

typedef long long int64;

using namespace std;

int main() {
    long double n, a, b;
    cin >> n >> a >> b;
    vector<int64> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    sort(s.begin(), s.end());
    int64 sum = accumulate(s.begin(), s.end(), 0LL);
    int64 diff = s.back() - s[0];

    long double p, q;
    if (diff != 0) {
        p = b / diff;
        q = (a * n - sum * p) / n;
    } else {
        cout << "-1" << endl;
        return 0;
    }

    std::cout << std::setprecision(14);
    cout << p << " " << q;
}