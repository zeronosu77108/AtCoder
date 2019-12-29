#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int main() {
    int n;
    int ans = 0;
    cin >> n;
    vector<long long> t(n);
    vector<long long> f(n);

    for (int i=0; i<n; i++) {
        int a; cin >> a;
        for (int j=0; j<a; j++) {
            int x,y;
            cin >> x >> y; x--;
            if (y) t[i] |= (1<<x);
            else f[i] |= (1<<x);
        }
    }

    for (int i=0; i<(1<<n); i++) {
        bool flag = true;
        int cnt = 0;

        for (int j=0; j<n; j++) {
            if (i>>j&1) {
                cnt++;
                if ((i|t[j]) != i) flag = false;
                if ((i&f[j]) != 0) flag = false;
            }
        }

        if (flag) {
            ans = max(ans, cnt);
        }
    }

    cout << ans << endl;
    return 0;
}