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
    int h1,w1,h2,w2;
    cin >> h1 >> w1 >> h2 >> w2;

    bool ans = (h1 == h2 || h1 == w2 || w1 == h2 || w1 == w2);
    cout << (ans? "YES" : "NO") << endl;
}