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

    for (int i=0; i<n; i++) {
        if ( s[i] == 'a') continue;
        if ( s[i] == 'i') continue;
        if ( s[i] == 'u') continue;
        if ( s[i] == 'e') continue;
        if ( s[i] == 'o') continue;
        cout << s[i];
    }
    cout << endl;
}