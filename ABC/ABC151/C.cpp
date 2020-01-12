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
    int64 n,m;
    int64 ac,wa;

    ac = wa = 0;

    cin >> n >> m;
    vector<bool> close(n+1,false);
    map<int,int> cnt;

    for (int64 i=0; i<m; i++) {
        int64 p;
        string s;
        cin >> p >> s;
        if (close[p]) continue;

        if (s == "AC") {
            ac++;
            close[p] = true;
        }
        else if (s == "WA") cnt[p]++;

    }

    for (int i=1; i<=n; i++) {
        if (close[i]) wa += cnt[i];
    }

    cout << ac << " " << wa << endl;
}