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
    vector<string> s(n);
    for (int i=0; i<n; i++) cin>>s[i];

    for (int i=0; i<n; i++) {
        for (int j=n-1; j>=0; j--) cout << s[j][i];
        cout << endl;
    }
}