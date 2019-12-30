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

const int N_MAX = 1000001;

int main() {
    int n;
    int ans = 0;
    cin >> n;
    vector<int> s(N_MAX,0);
    for (int i=0; i<n; i++) {
        int a,b;
        cin >> a >> b;
        s[a]++;
        s[b+1]--;
    }

    for (int i=0; i<N_MAX; i++) {
        s[i+1] += s[i];
    }

    for (int i=0; i<=N_MAX; i++) ans = max(ans, s[i]);
    cout << ans << endl;
}