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
    int n;
    int ans = 0;
    cin >> n;

    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        switch(a%6) {
            case 2:
            case 4:
                ans++;
                break;
            case 5:
                ans+=2;
                break;
            case 0:
                ans+=3;
                break;
        }
    }
    cout << ans << endl;
}