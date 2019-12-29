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
    string s,t;
    cin >> s >> t;
    int n = s.size();

    bool ans = true;
    char at = '-';
    for (int i=0; i<n; i++) {
        if (s[i] == t[i]) continue;
        if (s[i] != '@' && t[i] != '@') ans = false;
        if (t[i] == '@') swap(s[i], t[i]);
        switch(t[i]) {
            case 'a':
            case 't':
            case 'c':
            case 'o':
            case 'd':
            case 'e':
            case 'r':
                break;
            default:
                ans = false;
        }
    }
    cout << (ans? "You can win" : "You will lose") << endl;
}