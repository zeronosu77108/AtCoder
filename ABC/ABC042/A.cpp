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
    vector<int> haiku(3);
    for (int i=0; i<3; i++) cin >> haiku[i];
    sort(haiku.begin(), haiku.end());

    if (haiku[0] == 5 && haiku[1] == 5 && haiku[2] == 7)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}