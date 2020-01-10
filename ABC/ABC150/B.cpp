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
    int ans = 0;
    string s;
    cin >> n >> s;

    for (int i=0; i<n-2; i++) {
        if (s[i]=='A' && s[i+1]=='B' && s[i+2]=='C') ans++;
    }

    cout << ans << endl;
}