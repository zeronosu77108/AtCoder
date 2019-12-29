#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>

using namespace std;

int main() {
    int n;
    double ans = 0;
    cin >> n;

    for (int i=0; i<n; i++) {
        double x;
        string y;
        cin >> x >> y;
        if (y == "JPY") ans += x;
        else ans += 380000.0 * x;
    }

    cout << fixed << setprecision(7) << ans << endl;
}