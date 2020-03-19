#include <iostream>
#include <vector>

using namespace std;

using int64 = long long;

int main() {
    int n,k;
    cin >> n >> k;

    vector<int64> x(n);
    vector<int64> y(n);
    for (int i=0; i<n; i++) cin >> x[i] >> y[i];

    vector<int64> xv = x;
    vector<int64> yv = y;

    sort(xv.begin(), xv.end());
    sort(yv.begin(), yv.end());

    int64 ans = LONG_MAX;
    for (int xs=0; xs<n; xs++) {
        for (int xe=xs+1; xe<n; xe++) {
            for (int ys=0; ys<n; ys++) {
                for (int ye=ys+1; ye<n; ye++) {

                    int cnt = 0;
                    for (int i=0; i<n; i++) {
                        if (xv[xs] <= x[i] && x[i] <= xv[xe] && yv[ys] <= y[i] && y[i] <= yv[ye])
                            cnt++;
                    }
                    if (cnt >= k) {
                        ans = min(ans, (xv[xe] - xv[xs]) * (yv[ye] - yv[ys]));
                    }
              }
            }
        }
    }

    cout << ans << endl;
}