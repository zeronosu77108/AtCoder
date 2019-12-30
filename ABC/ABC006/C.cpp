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


int main() {
    int n,m;
    cin >> n >> m;
    int a,o,b;
    a = o = b = 0;

    if (m < 2*n || 4*n < m) {
        puts("-1 -1 -1");
        return 0;
    }

    if (m%2) {
        o = 1;
        n--; m -= 3;
    }

    b = m / 2 - n;
    a = n - b;
    cout << a << " " << o << " " << b << endl;
}