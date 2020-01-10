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
    vector<int> p(4);
    for (int i=0; i<4; i++) cin >> p[i];
    sort(p.rbegin(), p.rend());
    int ans = p[0] + p[1] + p[2];
    int e,f;
    cin >> e >> f;
    ans += max(e,f);


    cout << ans << endl;


}