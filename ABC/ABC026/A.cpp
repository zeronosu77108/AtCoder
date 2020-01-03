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
    int a;
    cin >> a;
    int ans = 0;
    for (int i=1; i<a; i++) {
        ans = max(ans, i*(a-i));
    }
    cout << ans << endl;
}