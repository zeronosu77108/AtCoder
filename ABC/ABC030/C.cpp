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
    int64 n,m,x,y;
    cin >> n >> m >> x >> y;

    priority_queue<int64,vector<int64>,greater<>> a;
    priority_queue<int64,vector<int64>,greater<>> b;

    for (int64 i=0; i<n; i++) {
        int64 ai; cin >> ai;
        a.push(ai);
    }
    for (int64 i=0; i<m; i++) {
        int64 bi; cin >> bi;
        b.push(bi);
    }

    int64 ans = 0;
    int64 time = 0;
    while(true) {
        while(!a.empty() && time > a.top()) a.pop();
        if (a.empty()) break;
        time = a.top() + x; a.pop();

        while(!b.empty() && time > b.top()) b.pop();
        if (b.empty()) break;
        time = b.top() + y; b.pop();

        ans++;
    }

    cout << ans << endl;
}