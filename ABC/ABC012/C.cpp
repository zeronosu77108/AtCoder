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
    cin >> n;
    int rest = 2025 - n;

    for (int i=1; i<=9; i++) {
        if (rest%i == 0 && 10 > rest/i)
            cout << i << " x " << rest/i << endl;
    }
}