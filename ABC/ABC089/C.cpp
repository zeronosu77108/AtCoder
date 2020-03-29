#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
using int64 = long long;


int main() {
    int n;
    cin >> n;
    vector<int64> cnt(6, 0);
    set<string> names;
    map<char, int> to;
    to['M'] = 1;
    to['A'] = 2;
    to['R'] = 3;
    to['C'] = 4;
    to['H'] = 5;


    for (int i=0; i<n; i++) {
        string s;
        cin >> s;
        if (names.find(s) != names.end()) continue;
        names.insert(s);
        cnt[to[s[0]]]++;
    }

    for (int i=1; i<6; i++) cerr<<cnt[i]<<" ";cerr<<endl;
    int64 ans = 0;
    for (int i=1; i<6; i++) {
        for (int j=i+1; j<6; j++) {
            for (int k=j+1; k<6; k++) {
                ans += cnt[i] * cnt[j] * cnt[k];
            }
        }
    }
    cout << ans << endl;

}