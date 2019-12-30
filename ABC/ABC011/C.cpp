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

bool ok(const int n, const vector<int>& ng) {
    if (n < 0) return false;

    for (auto ng1 : ng) {
        if (ng1 == n) return false;
    }
    return true;
}

int main() {
    int n;
    bool ans = false;
    vector<int> ng(3);
    cin >> n;
    for (int i=0; i<3; i++) cin>>ng[i];

    for (int i=0; i<100; i++) {
        bool f = false;
        if (!ok(n,ng)) break;

        if (ok(n-3,ng)) n-=3;
        else if (ok(n-2,ng)) n-=2;
        else if (ok(n-1,ng)) n-=1;
        else f = true;

        if (n == 0) {
            ans = true;
            break;
        }
        if (f) {
            ans = false;
            break;
        }
    }

    cout << (ans? "YES" : "NO") << endl;
}