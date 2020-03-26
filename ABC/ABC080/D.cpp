#include <iostream>
#include <vector>

using namespace std;
using int64 = long long;

int main() {
    int64 n,c;
    cin >> n >> c;
    const int64 LIM = 1e6;
    vector<vector<int64>> imos(c+1, vector<int64>(LIM + 10, 0));
    for (int64 i=0; i<n; i++) {
        int64 s,t,ci;
        cin >> s >> t >> ci;
        imos[ci][s-1]++;
        imos[ci][t]--;
    }

    int64 ans = 0;
    for (int64 i=0; i<LIM; i++) {
        int64 cnt = 0;
        for (int j=1; j<=c; j++) {
            imos[j][i + 1] += imos[j][i];
            if (imos[j][i] >= 1) cnt++;
        }
        ans = max(ans, cnt);
    }


    cout << ans << endl;
}