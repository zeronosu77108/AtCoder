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

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main() {
    int t;
    int ans;
    string s;
    cin >> s >> t;
    int n = s.size();

    int x = 0;
    int y = 0;
    int cnt = 0;

    for (int i=0; i<n; i++) {
        switch (s[i]) {
            case '?':
                cnt++;
                break;
            case 'L':
                x--;
                break;
            case 'R':
                x++;
                break;
            case 'U':
                y++;
                break;
            case 'D':
                y--;
                break;
        }
    }

    int m = abs(x) + abs(y);
    if (t == 1) {
        ans = m + cnt;
    } else {
        if (m < cnt) {
            ans = abs(cnt - m) % 2;
        } else {
            ans = m - cnt;
        }
    }

    cout << ans << endl;
}