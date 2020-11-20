#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// 約数列挙
template <class T> vector<T> enumDivisors(T n, bool sorted=false) {
    vector<T> res(1,1);

    for (long long i=2; i*i<=n; i++) {
        if (n%i==0) {
            res.push_back(i);
            if (i*i != n) res.push_back(n/i);
        }
    }

    res.push_back(n);
    if (sorted) sort(res.begin(), res.end());
    return res;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector a(n, 0LL);
    for (int i=0; i<n; i++) cin >> a[i];
    auto sum = accumulate(a.begin(), a.end(), 0LL);

    auto divisors = enumDivisors(sum);

    long long ans = 0;
    for (auto d : divisors) {
        vector r(n, 0LL);
        for (int i=0; i<n; i++) r[i] = a[i] % d;
        sort(r.begin(), r.end());


        vector left(n+1, 0LL);
        for (int i=0; i<n; i++) left[i+1] = left[i] + r[i];
        vector right(n+1, 0LL);
        for (int i=n; i>0; i--) right[i-1] = right[i] + (d-r[i-1]);

        for (int i=0; i<=n; i++) {
            if (left[i] == right[i] && left[i] <= k) {
                ans = max(ans, d);
            }
        }
    }

    cout << ans << endl;
}