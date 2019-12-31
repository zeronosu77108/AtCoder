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
    int a,b,c;
    cin >> a >> b >> c;
    bool plus = (a+b) == c;
    bool minus = (a-b) == c;

    char ans;
    if (plus && minus) ans = '?';
    else if (plus) ans = '+';
    else if (minus) ans = '-';
    else ans = '!';

    cout << ans << endl;
}