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

int main() {
    int64 n,m,v,p;
    cin >> n >> m >> v >> p;
    vector<int64> a(n);
    for (int64 i=0; i<n; i++) cin >> a[i];
    sort(a.rbegin(), a.rend());

    int64 l=0, r=n;
    while(l+1 < r) {
        int64 g = (l+r)/2;
        bool f = true;
        vector<bool> full(n);

        int64 balance = m*v;

        int64 tmp = p - 1;
        for (int i=0; i<n; i++) {
            if (full[i]) continue;
            if (tmp <= 0) break;
            tmp--; full[i] = true;
        }

        for (int64 i=0; i<n; i++) {
            if (full[i]) balance -= m;
            else {
                int64 x = a[g] + m - a[i];
                if (x < 0) {
                    f = false;
                    break;
                }
                balance -= min(x, m);
            }
        }

        if (balance > 0) f = false;
        (f ? l : r) = g;
    }

    cout << l + 1 << endl;
}