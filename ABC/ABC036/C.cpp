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
    for (int i=0; i<n; i++) cin >> a[i];
    vector<int> c = a;
    sort(c.begin(), c.end());
    c.erase( unique(c.begin(), c.end()), c.end());

    for (int i=0; i<n; i++) {
        auto it = lower_bound(c.begin(), c.end(), a[i]);
        cout << it - c.begin() << endl;
    }
}