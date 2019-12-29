#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

bool check(long i) {
    vector<bool> n(10);
    while(i > 0) {
        n[ i%10 ] = true;
        i/=10;
    }
    return n[3] && n[5] && n[7];
}

int dfs(const long n, long i) {
    if (i > n) return 0;
    long res = dfs(n, i*10+3) + dfs(n,i*10+5) + dfs(n,i*10+7);
    return res + check(i);
}

int main() {
    long n;
    cin >> n;
    long ans = dfs(n,0);

    cout << ans << endl;
}
