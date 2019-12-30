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
    cin >> s;
    int n = s.size();

    if ('a' <= s[0] && s[0] <= 'z') s[0] += 'A' - 'a';
    for (int i=1; i<n; i++) {
        if ('A' <= s[i] && s[i] <= 'Z') s[i] -= 'A' - 'a';
    }

    cout << s << endl;
}