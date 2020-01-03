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

void dfs(int n, string s) {
    if (n == 0) cout << s << endl;
    else {
        dfs(n-1, s + "a");
        dfs(n-1, s + "b");
        dfs(n-1, s + "c");
    }
}

int main() {
    int n;
    cin >> n;
    dfs(n, "");
}