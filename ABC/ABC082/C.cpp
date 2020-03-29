#include <iostream>
#include <vector>
#include <utility>

using namespace std;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    vector<P> l;
    l.emplace_back(a[0], 0);
    for (int i=0; i<n; i++) {
        if (l.back().first == a[i]) l.back().second++;
        else l.emplace_back(a[i], 1);
    }


    int ans = 0;
    for (auto p : l) {
        if (p.first < p.second) ans += p.second - p.first;
        if (p.first > p.second) ans += p.second;
    }

    cout << ans << endl;
}