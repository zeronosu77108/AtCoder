#include <iostream>
#include <vector>

using namespace std;
using int64 = long long;

const vector<int> dx = {-1, +0, +1, -1, +0, +1, -1, +0, +1};
const vector<int> dy = {+1, +1, +1, +0, +0, +0, -1, -1, -1};

int main() {
    int64 n, m;
    cin >> n >> m;

    int64 ans = (n-2) * (m-2);
    if (n == 1 || m == 1) ans = max(0LL, n*m - 2);
    if (n == 1 && m == 1) ans = 1;

    cout << ans << endl;
}
