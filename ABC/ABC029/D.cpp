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

void naive(int n) {
    int ans = 0;
    for (int i=1; i<=n; i++) {
        int j = i;
        while (j != 0) {
            if (j % 10 == 1) ans++;
            j /= 10;
        }
    }
    cout << ans << endl;
}

int main() {
    int n;
    int ans = 0;
    cin >> n;
    n++;
    int d = 0;
    for (int i=n; i!=0; i/=10) d++;

    int t = 1;
    for (int i=0; i<d+1; i++) {
        ans += t * (n / (t*10));
        ans +=  max(0, min(t, (n%(t*10)) - t));
        t *= 10;
    }
    cout << ans << endl;
}