#include <iostream>
#include <vector>

using namespace std;
using int64 = long long;

int main() {
    int h,w;
    cin >> h >> w;
    vector<vector<int64>> c(10, vector<int64> (10));
    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
            cin >> c[i][j];
        }
    }

    for (int k=0; k<10; k++) {
        for (int i=0; i<10; i++) {
            for (int j=0; j<10; j++) {
                c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
            }
        }
    }


    int64 ans = 0;
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            int a;
            cin >> a;
            if (a < 0) continue;
            ans += c[a][1];
        }
    }

    cout << ans << endl;
}