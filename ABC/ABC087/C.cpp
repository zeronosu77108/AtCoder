#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a1(n);
    vector<int> a2(n);
    for (int i=0; i<n; i++) cin >> a1[i];
    for (int i=0; i<n; i++) cin >> a2[i];

    int ans = 0;
    for (int i=0; i<n; i++) {
        int cnt = 0;
        cnt += accumulate(a1.begin(), a1.begin()+i+1, 0);
        cnt += accumulate(a2.begin()+i,a2.end(), 0);
        ans = max(ans, cnt);
    }

    cout << ans << endl;
}