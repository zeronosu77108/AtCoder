#include <iostream>
#include <utility>
#include <vector>

using namespace std;
using int64 = long long;
using P = pair<int64,int64>;

int main() {
    int64 n,m;
    cin >> n >> m;
    vector<P> ab;
    for (int i=0; i<n; i++) {
        int64 a,b;
        cin >> a >> b;
        ab.emplace_back(a,b);
    }

    sort(ab.begin(), ab.end());

    int64 ans = 0;
    for (auto p : ab) {
        int64 a,b;
        tie(a,b) = p;
        ans += a * min(m,b);
        m -= b;
        if (m <= 0) break;
    }

    cout << ans << endl;
}
