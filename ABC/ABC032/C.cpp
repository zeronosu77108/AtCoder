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
    int64 n,k;
    int64 ans = 0;
    cin >> n >> k;
    vector<int64> s(n);
    for (int i=0; i<n; i++) cin >> s[i];

    int64 sum = 1;
    int64 r = 0;
    for (int64 l=0; l<n; l++) {
        while(r<n && sum*s[r] <= k) sum *= s[r++];
        ans = max(ans, r-l);
        if (l == r) sum *= s[r++];
        if (s[l] == 0) break;
        sum /= s[l];
    }

    if (any_of(s.begin(), s.end(), [](int64 x){return x==0;})) ans = n;

    cout << ans << endl;
}