#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int main() {
    int n;
    int ans = INT_MAX;
    string s;
    cin >> n >> s;
    vector<int> w(n+2,0);
    vector<int> e(n+2,0);

    w[1] = s[0] == 'W';
    e[1] = s[0] == 'E';
    for (int i=1; i<n; i++) w[i+1] = w[i] + (s[i]=='W');
    for (int i=1; i<n; i++) e[i+1] = e[i] + (s[i]=='E');

    for (int i=0; i<n; i++) {
        ans = min(ans, w[i] + e[n]-e[i+1]);
    }

    cout << ans << endl;
}