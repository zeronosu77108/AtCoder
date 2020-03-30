#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n,m,x;
    cin >> n >> m >> x;
    vector<int> a(m);
    for (int i=0; i<m; i++) cin >> a[i];

    auto it = upper_bound(a.begin(),a.end(), x);
    cout << min(it - a.begin(), a.end() - it) << endl;
}