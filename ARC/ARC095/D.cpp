#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;


int main() {
    long n;
    cin >> n;

    vector<long> a(n);
    for (long i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());
    long cn = a.back();
    long r = 0;

    long cm = -1;
    for (long i = 0; i < n - 1; i++) {
        long tmp = a[i] * (cn - a[i]);
        if (cm < tmp) {
            cm = tmp;
            r = a[i];
        }
    }
    cout << cn << " " << r << endl;
}