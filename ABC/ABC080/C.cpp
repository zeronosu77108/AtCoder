#include <iostream>
#include <vector>
#include <utility>
#include <map>

using namespace std;

using int64 = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;


    vector<int> f(n, 0);
    for (int i=0; i<n; i++) {
        for (int j=0; j<10; j++) {
            int fi; cin >> fi;
            f[i] |= fi<<j;
        }
    }


    vector<vector<int>> p(n, vector<int>(11));
    for (int i=0; i<n; i++) {
        for (int j=0; j<=10; j++) {
            cin >> p[i][j];
        }
    }


    int64 ans = INT_MIN;
    for (int i=1; i<(1<<10); i++) {
        int64 cnt = 0;
        for (int j=0; j<n; j++) {
            int c = __builtin_popcount(i & f[j]);
            cnt += p[j][c];
        }
        ans = max(ans, cnt);
    }

    cout << ans << endl;
}