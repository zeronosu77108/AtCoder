#include <iostream>
#include <vector>

using namespace std;
using int64 = long long;

int main() {
    int64 n;
    cin >> n;
    vector<int64> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int _n = a.back(); a.pop_back();
    double mid = _n / 2.0;

    int pre = INT_MAX;
    int _r = 0;

    for (auto ai : a) {
        double ab = mid - ai;
        if (ab < 0) ab = -ab;
        if (pre > ab) pre=ab,_r=ai;
    }

    cout << _n << " " << _r << endl;
}

/*
 * nCr = n! / r! * (n-r)!
 */