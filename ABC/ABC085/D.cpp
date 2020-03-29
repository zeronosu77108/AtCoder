#include <iostream>
#include <vector>
#include <utility>

using namespace std;
using P = pair<int,int>;

int main() {
    int n,h;
    cin >> n >> h;
    vector<P> ab;
    for (int i=0; i<n; i++) {
        int a,b;
        cin >> a >> b;
        ab.emplace_back(a,b);
    }

    sort(ab.begin(), ab.end());
    P _max = ab.back();
    ab.pop_back();

    auto cmp = [](const P& x, const P& y){return x.second<y.second;};
    sort(ab.begin(), ab.end(), cmp);

    int ans = 0;
    while(h > 0) {
        ans++;
        if (h - _max.second <= 0) h -= _max.second;
        else if (!ab.empty() && _max.first < ab.back().second) {
            h -= ab.back().second;
            ab.pop_back();
        } else {
            int c = ((h - _max.second + _max.first - 1) / _max.first );
            h -= c * _max.first;
            ans += c - 1;
        }
    }
    cout << ans << endl;
}
/*
 * 1000000000
 *   99999999
 */