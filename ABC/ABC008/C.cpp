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
struct aaa{aaa(){cin.tie(nullptr); ios::sync_with_stdio(false); cout<<fixed<<setprecision(20);};}aaa;

typedef long long int64;

int64 frac(int64 n) {
    if (n <= 0) return 1;
    return n * frac(n-1);
}

int main() {
    int64 n;
    long double ans = 0;
    cin >> n;
    vector<int64> c(n);
    for (int i=0; i<n; i++) cin>>c[i];
    sort(c.begin(), c.end());

    vector<int64> index(n);
    iota(index.begin(), index.end(), 0);

    do {
        vector<bool> f(n,true);

        for (int64 i=0; i<n; i++) {
            for (int64 j=i+1; j<n; j++) {
                if (c[index[j]]%c[index[i]] == 0) f[index[j]] = !f[index[j]];
            }
        }

        for (int64 i=0; i<n; i++) {
            if (!f[index[i]]) continue;
            ans++;
        }
    } while (next_permutation(index.begin(), index.end()));

    cout << ans/frac(n) << endl;
}