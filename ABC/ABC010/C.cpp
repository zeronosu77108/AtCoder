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
    int tx1,ty1,tx2,ty2;
    bool ans = false;
    int t,v,n;
    cin >> tx1 >> ty1 >> tx2 >> ty2;
    cin >> t >> v;

    cin >> n;
    for (int i=0; i<n; i++) {
        int x,y;
        cin >> x >> y;
        double d1 = sqrt( pow(tx1-x,2) + pow(ty1-y,2));
        double d2 = sqrt( pow(tx2-x, 2) + pow(ty2-y, 2));
        if (d1 + d2 <= t*v) ans = true;

        if (ans) break;
    }

    cout << (ans? "YES" : "NO") << endl;
}