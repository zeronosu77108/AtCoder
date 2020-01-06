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
    int n,q;
    cin >> n >> q;
    vector<int> ans(n+2,0);
    for (int i=0; i<q; i++) {
        int l,r;
        cin >> l >> r;
        ans[l]++;
        ans[r+1]--;
    }

    for (int i=0; i<=n; i++) {
       ans[i+1] -= ans[i];
    }

    for (int i=1; i<=n; i++) {
        cout << abs(ans[i] % 2);
    }
    cout << endl;
}