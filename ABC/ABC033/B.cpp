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
    string ans = "";
    cin >> n;
    vector<string> s(n);
    vector<int> p(n);

    for (int i=0; i<n; i++) cin>>s[i] >>p[i];
    int sum = accumulate(p.begin(), p.end(), 0);

    for (int i=0; i<n; i++) {
        if (sum/2 < p[i]) ans = s[i];
    }

    cout << (ans==""? "atcoder" : ans) << endl;
}