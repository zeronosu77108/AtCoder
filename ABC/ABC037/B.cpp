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
    vector<int> a(n+1, 0);

    for (int i=0; i<q; i++) {
        int l,r,t;
        cin >> l >> r >> t;
        for (int j=l; j<=r; j++) a[j]=t;
    }


    for (int i=1; i<=n; i++) cout << a[i] << endl;
}