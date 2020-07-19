#include <iostream>
#include <vector>

using namespace std;
using int64 = long long;
using P = pair<int64,int64>;

const int64 MOD = 1000000007;
vector<int64> _fact(100001,0);
constexpr int64 fact(int64 n) {
    if (n <= 0) return 1;
    return _fact[n] = ((n%MOD) * (fact(n-1)%MOD)) % MOD;
}

int main() {
    fact(100000);

    int64 n;
    cin >> n;
    vector t(n,0);
    for (int64 i=0; i<n; i++) cin >> t[i];
    sort(t.begin(), t.end());

    int64 sum = 0;
    {
        int64 tmp = 0;
        for (const auto &item1 : t) {
            tmp += item1;
            sum += tmp;
        }
    }

    vector<P> l;
    l.emplace_back(t[0],0);
    for (const auto &item : t) {
        if (l.back().first == item) l.back().second++;
        else l.emplace_back(item, 1);
    }


    int64 ans = 1;
    for (const auto& [a,b] : l) {
        ans *= _fact[b];
        ans %= MOD;
    }

    cout << sum << endl;
    cout << ans << endl;
}