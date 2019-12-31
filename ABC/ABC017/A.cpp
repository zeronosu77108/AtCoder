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
    int ans = 0;
    for (int i=0; i<3; i++) {
        int s,e;
        cin >> s >> e;
        ans += s*e/10;
    }

    cout << ans << endl;
}