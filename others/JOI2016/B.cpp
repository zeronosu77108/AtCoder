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
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    for (int k=1; k<=m; k++) {
        for (int j=0; j<n-1; j++) {
            if (a[j]%k > a[j+1]%k) swap(a[j], a[j+1]);
        }
    }
    for (auto ai : a) cout << ai << endl;
}