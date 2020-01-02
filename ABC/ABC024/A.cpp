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
    int a,b,c,k,s,t;
    cin >> a >> b >> c >> k;
    cin >> s >> t;

    cout << (a*s + b*t - (s+t>=k? (s+t)*c : 0)) << endl;
}