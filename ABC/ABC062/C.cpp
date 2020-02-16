#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

using int64 = long long;

int64 calc(int64 h, int64 w) {
    int64 res = INT_MAX;

    for (int i=1; i<h; i++) {
        int64 a = i * w;

        int64 rest_h = h - i;
        {
            int64 b = ceil(rest_h/2.0) * w;
            int64 c = floor(rest_h/2.0) * w;

            int64 s_max = max(a, max(b,c));
            int64 s_min = min(a, min(b,c));
            res = min(res, s_max - s_min);
        }

        {
            int64 b = ceil(w/2.0) * rest_h;
            int64 c = floor(w/2.0) * rest_h;
            int64 s_max = max(a, max(b,c));
            int64 s_min = min(a, min(b,c));
            res = min(res, s_max - s_min);
        }
    }
    return res;
}

int main() {
    int64 h, w;
    cin >> h >> w;

    int64 ans = calc(h,w);
    ans = min(ans, calc(w,h));


    cout << ans << endl;
}