#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i=0; i<n; i++) cin >> h[i];

    vector<int> hc(n,0);
    vector<int> in(n);
    iota(in.begin(), in.end(), 0);
    auto c = [&](const int& i){return h[i]!=hc[i];};
    int ans = 0;
    while(any_of(in.begin(), in.end(), c)) {
        int i = 0;
        ans++;
        while(h[i] == hc[i]) i++;
        while(i<n && h[i] != hc[i]) hc[i++]++;
    }
    cout << ans << endl;
}
