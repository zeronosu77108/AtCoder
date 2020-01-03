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
    string ans;
    cin >> n;

    if (n == 100) ans = "Perfect";
    else if (n >= 90) ans = "Great";
    else if (n >= 60) ans = "Good";
    else ans = "Bad";

    cout << ans << endl;
}