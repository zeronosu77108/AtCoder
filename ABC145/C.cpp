#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <numeric>

using namespace std;

long long frac(long long n) {
    long long res = 1;
    for (int i=1; i<=n; i++) res *= i;
    return res;
}
int main() {
    long long n;
    long double ans = 0;
    long double sum = 0;
    cin >> n;
    vector<long double> x(n);
    vector<long double> y(n);

    for (int i=0; i<n; i++) cin>>x[i]>>y[i];

    vector<int> c(n);
    iota(c.begin(), c.end(), 0);

    do {
        for (int i=0; i<n-1; i++) {
            sum += sqrt( pow(x[c[i]]-x[c[i+1]],2) + pow(y[c[i]]-y[c[i+1]],2));
        }
    } while(next_permutation(c.begin(), c.end()));

    cout << setprecision(14) << (sum/frac(n)) << endl;
}