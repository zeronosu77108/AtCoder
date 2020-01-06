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
    bool ans = true;
    cin >> n;
    int d = n % 10;

    for (int i=0; i<4; i++) {
        ans = ans && (d == n%10);
        n /= 10;
    }

    cout << (ans? "SAME" : "DIFFERENT") << endl;
}