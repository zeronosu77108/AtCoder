#include <iostream>
#include <vector>
#include <utility>

using namespace std;
using P = pair<int, int>;

int main() {
    int n, k;
    cin >> n >> k;

    int e = (n-2)*(n-1) / 2;
    if (e < k) {
        cout << -1 << endl;
        return 0;
    }

    vector<P> ans;
    for (int i=2; i<=n; i++) ans.emplace_back(1, i);

    for (int i=2; i<=n; i++) {
        if (e == k) break;

        for (int j=i+1; j<=n; j++) {
            ans.emplace_back(i, j);
            e--;
            if (e == k) break;
        }
    }


    cout << ans.size() << endl;
    for (auto [v, u] : ans) {
        cout << v << " " << u << endl;
    }
}