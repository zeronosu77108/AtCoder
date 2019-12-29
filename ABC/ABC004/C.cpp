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

void naive(int i, string& s) {
    swap(s[i%5], s[i%5+1]);
}

int main() {
    int n;
    cin >> n;
    string s = "123456";
    n %= 60;
    for (int i=0; i<n; i++) {
        naive(i,s);
    }

    cout << s << endl;
}