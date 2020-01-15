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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin>>a[i];
    vector<int> ans(n);
    iota(ans.begin(), ans.end(), 0);

    auto c = [&](int x, int y){return a[x] > a[y];};
    sort(ans.begin(), ans.end(), c);

    for (auto an : ans) cout << an + 1 << endl;
}