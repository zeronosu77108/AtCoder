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

bool ok(int i, const int& n, vector<bool>& d) {
    if (i < n) return false;
    while(i != 0) {
        if (d[i%10]) return false;
        i /= 10;
    }
    return true;
}

int main() {
    int n,k;
    cin >> n >> k;
    vector<bool> ng(10);
    for (int i=0; i<k; i++) {
        int d; cin>>d;
        ng[d] = true;
    }

    for (int i=1; i<=INT_MAX; i++) {
        if (ok(i,n,ng)) {
            cout << i << endl;
            break;
        }
    }
}