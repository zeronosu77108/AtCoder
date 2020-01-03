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

    int sum = 0;
    vector<int> r(n);

    for (int i=0; i<n; i++) cin>>r[i];
    sort(r.begin(), r.end());

    for (int i=0; i<n; i++) {
        int ri = r[i]*r[i];
        if (i%2) sum -= ri;
        else sum += ri;
    }

    cout << abs(sum * M_PI) << endl;
}