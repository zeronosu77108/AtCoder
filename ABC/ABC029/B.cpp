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
    int ans = 0;
    for (int i=0; i<12; i++) {
        string s;
        cin >> s;
        if (any_of(s.begin(), s.end(),
            [](char c){return c=='r';})) ans++;
    }
    cout << ans << endl;
}