#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<int> xv(n);
    vector<int> yv(m);
    for (int i = 0; i < n; i++) cin >> xv[i];
    for (int i = 0; i < m; i++) cin >> yv[i];

    sort(xv.begin(), xv.end());
    sort(yv.begin(), yv.end());

    int z = max(xv.back(), x) + 1;


    bool ans = z<=y &&  z <= yv[0];
    cout << (ans ? "No War" : "War") << endl;
}