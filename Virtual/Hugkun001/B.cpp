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
    int ans = 0;
    string s;
    cin >> n >> s;
    for (int i=0; i<n; i++) {
        string s1,s2;
        s1 = s.substr(0, i);
        s2 = s.substr(i, s.size() - i);

        map<char,bool> m1,m2;

        for (int j=0; j<s1.size(); j++) m1[s1[j]] =true;
        for (int j=0; j<s2.size(); j++) m2[s2[j]] =true;

        int cnt = 0;
        for (int j=0; j<n; j++) {
            char c = 'a' + j;
            if (m1[c] && m2[c]) cnt++;
        }
        ans = max(ans, cnt);
    }

    cout << ans << endl;
}