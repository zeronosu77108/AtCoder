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
    int l1,l2,l3;
    int ans = 0;
    cin >> l1 >> l2 >> l3;

    if (l1 == l2) ans = l3;
    else if (l1 == l3) ans = l2;
    else ans = l1;

    cout << ans << endl;
}