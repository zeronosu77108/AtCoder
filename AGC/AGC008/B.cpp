#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector a(n, 0L);
    for (int i=0; i<n; i++) cin >> a[i];

    // 1区画以外は好きに塗ることができる。 → 基本的に正の数を採用
    long sum = 0;
    for (int i=0; i<n; i++) sum += max(0L, a[i]);

    vector csum(2, vector(n+1, 0L));
    for (int i=0; i<n; i++) {
        csum[0][i+1] += csum[0][i];
        csum[1][i+1] += csum[1][i];
        csum[a[i]<0][i+1] += a[i];
    }

    long ans = 0;
    for (int i=0; i<=n-k; i++) {
        long p = csum[0][i+k] - csum[0][i];
        long m = csum[1][i+k] - csum[1][i];

        // 黒く塗る → m が追加される
        // 白く塗る → p が減る
        ans = max({ans, sum+m, sum-p});
    }
    cout << ans << endl;
}