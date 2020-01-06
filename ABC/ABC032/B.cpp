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
    string s;
    int k;
    cin >> s >> k;
    int n = s.size();
    map<string,bool> mp;

    for (int i=0; i<n; i++) {
        if (i+k-1 >= n) continue;
        mp[s.substr(i, k)] = true;
    }

    cout << mp.size() << endl;
}