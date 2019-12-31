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

void _reverse(int l, int r, string &s) {
    string t;
    t = s;

    for (int i=l; i<=r; i++) {
        t[r-(i-l)] = s[i];
    }
    s = t;
}

int main() {
    string s;
    int n;
    cin >> s;
    cin >> n;
    for (int i=0; i<n; i++) {
        int l,r;
        cin >> l >> r;
        _reverse(l-1,r-1,s);
    }

    cout << s << endl;
}