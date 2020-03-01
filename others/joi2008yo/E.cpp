#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int r,c;
    cin >> r >> c;
    vector<vector<int>> a(r, vector<int> (c));

    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            cin >> a[i][j];
        }
    }

    int ans = 0;
    for (int i=0; i<(1<<r); i++) {
        vector<vector<int>> tmp = a;
        for (int j=0; j<r; j++) {
            if ((i>>j)&1)
                for (int k=0; k<c; k++) tmp[j][k] = !tmp[j][k];
        }

        int er = 0;
        for (int k=0; k<c; k++) {
            int cnt = 0;
            for (int j=0; j<r; j++) {
                if (tmp[j][k] == false) cnt++;
            }
            er += max(cnt, r-cnt);
        }
        ans = max(ans, er);
    }
    cout << ans << endl;
}
