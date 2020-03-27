#include <iostream>
#include <utility>
#include <vector>
#include <numeric>

using namespace std;
using P = pair<int,int>;

int main() {
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    vector<P> l;
    l.emplace_back(a[0], 0);
    for (int i=0; i<n; i++) {
        if (l.back().first == a[i]) l.back().second++;
        else l.emplace_back(a[i], 1);
    }

    auto cmp = [](P x, P y) {return x.second < y.second;};
    sort(l.rbegin(), l.rend(), cmp);


    int ans = 0;
    for (auto it=l.begin()+k; it<l.end(); it++) {
        ans += (*it).second;
    }

    cout << ans << endl;
}