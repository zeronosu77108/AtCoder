#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;
using int64 = long long;
using P = pair<int64,int64>;

template <typename T> bool chmin(T& a, const T b) {if(a>b){a=b;return true;}return false;};
template <typename T> bool chmax(T& a, const T b) {if(a<b){a=b;return true;}return false;};

int main() {
    int64 n;
    cin >> n;
    vector<int64> a(n);
    int64 _max = INT_MIN;
    int64 _min = INT_MAX;
    int64 uindex = 0;
    int64 lindex = 0;
    for (int64 i=0; i<n; i++) {
        cin >> a[i];
        if (chmin(_min, a[i])) lindex = i+1;
        if (chmax(_max, a[i])) uindex = i+1;
    }

    vector<P> ans;
    bool r = _max < 0;

    if (signbit(_max) != signbit(_min)) {
        int64 index = uindex;
        if (abs(_max) < abs(_min)) {
            index = lindex;
            r = true;
        }

        for (int64 i=1; i<=n; i++) {
            if (i == index) continue;
            ans.emplace_back(i, index);
        }
    }

    int64 k = ans.size();

    for (int64 i=1; i<n; i++) {
        ans.emplace_back(i+1, i);
    }

    if (r) reverse(ans.begin() + k , ans.end());

    cout << ans.size() << endl;
    for (int i=0; i<ans.size(); i++) {
        if (i>k-1 && r)
            cout << ans[i].first << " " << ans[i].second << endl;
        else
            cout << ans[i].second << " " << ans[i].first << endl;
    }
}