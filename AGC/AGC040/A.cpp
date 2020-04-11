#include <iostream>
#include <vector>
#include <string>
#include <numeric>

using namespace std;
using int64 = long long;

int main() {
    string s;
    cin >> s;
    int n = s.size() + 1;
    vector<int64> v(n,0);
    int64 now = 0;
    for (int i=1; i<n; i++) {
        if (s[i-1] == '>') continue;
        now = 0;
        while(i<n && s[i-1]=='<') v[i++] = ++now;
    }

    reverse(s.begin(), s.end());
    reverse(v.begin(), v.end());
    for (int i=1; i<n; i++) {
        if (s[i-1] == '<') continue;
        now = 0;
        while(i<n && s[i-1]=='>') {
            v[i] = max(v[i], ++now);
            i++;
        }
    }

    int64 ans = accumulate(v.begin(), v.end(), 0LL);
    cout << ans << endl;
}
