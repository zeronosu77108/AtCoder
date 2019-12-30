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
    map<string,int> b;
    for (int i=0; i<n; i++) {
        string s;
        cin >> s;
        b[s]++;
    }

    int bmax = -1;
    string ans = "";
    for (auto p : b) {
        if (bmax < p.second) ans = p.first, bmax=p.second;
    }

    cout << ans << endl;
}