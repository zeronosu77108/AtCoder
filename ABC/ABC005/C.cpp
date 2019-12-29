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
    int t,n,m;
    bool ans = true;
    cin >> t >> n;
    priority_queue<int,vector<int>, greater<int>> q;
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        q.push(a);
    }

    cin >> m;
    for (int i=0; i<m; i++) {
        int b;
        cin >> b;
        ans = false;
        while(1) {
            if (q.empty()) break;
            if (q.top() <= b && b <= q.top() + t) {
                q.pop();
                ans = true;
                break;
            }
            q.pop();
        }

    }

    cout << (ans? "yes" : "no") << endl;
}