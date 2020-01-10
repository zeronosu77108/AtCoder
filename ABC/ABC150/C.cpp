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
    int n;
    cin >> n;
    vector<int> p(n);
    vector<int> q(n);
    vector<int> per(n);
    for (int i=0; i<n; i++) cin >> p[i];
    for (int i=0; i<n; i++) cin >> q[i];
    per = p;

    sort(per.begin(), per.end());

    int cnt = 1;
    int pi,qi;
    do {
        if (p == per) pi = cnt;
        if (q == per) qi = cnt;
        cnt++;
    } while (next_permutation(per.begin(), per.end()));

    cout << abs(pi - qi) << endl;
}