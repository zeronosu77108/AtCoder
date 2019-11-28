#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int main() {
    int n,k;
    int ans = 0;
    cin >> n >> k;

    map<int,int> mp;
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        mp[a]++;
    }

    vector<int> ball;
    for (auto b : mp) {
        ball.push_back(b.second);
    }

    sort(ball.rbegin(), ball.rend());

    int cnt = 0;
    for (auto b : ball) {
        cnt++;
        if (cnt <= k) continue;
        ans += b;
    }

    cout << ans << endl;
}