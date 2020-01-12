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
    int n,k,m;
    cin >> n >> k >> m;
    vector<int> a(n-1);
    for (int i=0; i<n-1; i++) cin>>a[i];
    int sum = accumulate(a.begin(), a.end(), 0);
    int ans = max(0, m*n - sum);

    cout << (ans>k? -1 : ans) << endl;
}