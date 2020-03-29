#include <iostream>
#include <vector>
#include <utility>

using namespace std;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    vector<int> t(n);
    vector<int> x(n);
    vector<int> y(n);

    P p(0,0);
    int now = 0;
    for (int i=0; i<n; i++) cin >> t[i] >> x[i] >> y[i];

    bool ans = true;
    for (int i=0; i<n; i++) {
        int rest = t[i] - now;
        int dist = abs(p.first - x[i]) + abs(p.second - y[i]);
        if (rest < dist) {
            ans = false;
            break;
        }

        if (rest%2 != dist%2) {
            ans = false;
            break;
        }

        now = t[i];
        p = P(x[i],y[i]);
    }

    cout << (ans? "Yes" : "No") << endl;
}