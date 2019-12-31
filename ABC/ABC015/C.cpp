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

bool dfs(int i, int n, vector<vector<int>>& t) {
    if (i >= t.size()) return n == 0;

    bool res = false;
    for (auto ti : t[i]) {
        res = res || dfs(i+1, n^ti, t);
    }
    return res;
}

int main() {
    int n,k;
    cin >> n >> k;
    vector<vector<int>> t(n, vector<int> (k));

    for (int i=0; i<n; i++) {
        for (int j=0; j<k; j++) {
            cin >> t[i][j];
        }
    }

    bool ans = dfs(0,0,t);
    cout << (ans? "Found" : "Nothing") << endl;
}