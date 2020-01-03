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
typedef pair<int64, int64> P;


int main() {
    int n,d,k;
    cin >> n >> d >> k;
    vector<int64> l(d);
    vector<int64> r(d);

    for (int i=0; i<d; i++) cin >> l[i] >> r[i];

    for (int i=0; i<k; i++) {
        int64 s,t;
        cin >> s >> t;
        int j = 0;
        for (; j<d; j++) {
            if (s == t) break;

            if (s < t) {
                if (s > r[j] || s < l[j]) continue;
                s = min(r[j], t);
            } else {
                if (s <= l[j] || s > r[j]) continue;
                s = max(l[j], t);
            }
        }

        cout << min(d,j) << endl;
    }
}