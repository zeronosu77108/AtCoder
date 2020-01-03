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
    int64 n;
    cin >> n;

    int64 d = 0;
    for (int64 i=n; i>0; i/=2) d++;

    int64 cnt = 0;
    int64 i = 1;
    bool f = d % 2 == 0;
    while(i <= n) {
        i *= 2;
        if (cnt%2 == 0) { // 高橋
            if (!f) i++;
        } else {    // 青木
            if (f) i++;
        }
        cnt++;
    }
    cout << (cnt%2? "Aoki" : "Takahashi") << endl;
}