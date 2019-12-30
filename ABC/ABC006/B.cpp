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

const int mod = 10007;
vector<int> _tribotch(1000010, -1);
int tribochi(int n) {
    if (n <= 0) return 0;
    if (_tribotch[n] != -1) return _tribotch[n];
    _tribotch[n] = tribochi(n-1) + tribochi(n-2) + tribochi(n-3);
    _tribotch[n] %= mod;
    return _tribotch[n];
}

int main() {
    int n;
    cin >> n;
    _tribotch[1] = 0;
    _tribotch[2] = 0;
    _tribotch[3] = 1;
    cout << tribochi(n) << endl;
}