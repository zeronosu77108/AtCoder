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
    int l,h,n;
    cin >> l >> h >> n;

    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        if (h < a) cout << -1 << endl;
        else if (a < l) cout << l - a << endl;
        else cout << 0 << endl;
    }
}