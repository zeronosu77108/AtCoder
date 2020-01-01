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

string rle(string s) {
    string ans = "";
    int n = s.size();
    for (int i=0; i<n; i++) {
        int cnt = 1;
        while(i<n && s[i] == s[i+1]) i++,cnt++;
        ans += s[i] + to_string(cnt);
    }
    return ans;
}

int main() {
    string s;
    cin >> s;
    string ans = rle(s);

    cout << ans << endl;
}