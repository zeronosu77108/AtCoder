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
    int n,a,b;
    int ans = 0;
    cin >> n >> a >> b;

    for (int i=0; i<n; i++) {
        string s;
        int d;
        cin >> s >> d;
        if (s == "East") {
            ans += min(b, max(a, d));
        } else {
            ans -= min(b, max(a, d));
        }
    }

    string p;
    if (ans < 0) p = "West ";
    if (ans > 0) p = "East ";

    cout << p << abs(ans) << endl;
}