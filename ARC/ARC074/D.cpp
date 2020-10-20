#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>

using namespace std;

using int64 = long long;

int main() {
    int64 n;
    cin >> n;
    vector a(3*n, 0LL);
    for (int64 i=0; i<3*n; i++) cin >> a[i];

    int64 sum = accumulate(a.begin(), a.begin()+n, 0LL);
    vector prev(n+1, 0LL);
    prev[0] = sum;
    priority_queue<int64, vector<int64>, greater<>> q;
    for (int64 i=0; i<n; i++) q.emplace(a[i]);
    for (int64 i=n; i<2*n; i++) {
        sum += a[i];
        q.emplace(a[i]);
        prev[i-n+1] = sum -= q.top();
        q.pop();
    }


    sum = accumulate(a.end()-n, a.end(), 0LL);
    vector backv(n+1, 0LL);
    backv[n] = sum;
    priority_queue<int64> p;
    for (int64 i=3*n-1; i>=2*n; i--) p.emplace(a[i]);

    cerr<<endl;
    for (int64 i=2*n-1; i>=n; i--) {
        sum += a[i];
        p.emplace(a[i]);
        backv[i-n] = sum -= p.top();
        p.pop();
    }

    int64 ans = LONG_MIN;
    for (int64 i=0; i<=n; i++) {
        ans = max(ans, prev[i] - backv[i]);
    }

//    for (auto i : prev) cerr<<i<<" ";cerr<<endl;
//    for (auto i : backv) cerr<<i<<" ";cerr<<endl;


    cout << ans << endl;
}