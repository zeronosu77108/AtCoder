#include <iostream>
#include <vector>
#include <queue>

using namespace std;

using TP = tuple<int,int,int,int,int>;

int main() {
    int h, w;
    cin >> h >> w;
    vector a(h, vector(w, 0));
    vector b(h, vector(w, 0));

    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            cin >> a[i][j];
        }
    }

    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            cin >> b[i][j];
        }
    }

    vector dp(h, vector(w, vector((h+w)*80+1, false)));
    dp[0][0][abs(a[0][0] - b[0][0])] = true;

    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            for (int k=0; k<=(h+w)*80; k++) {
                if (dp[i][j][k]) {
                    if (i+1 < h) {
                        dp[i+1][j][k + abs(a[i+1][j] - b[i+1][j])] = true;
                        dp[i+1][j][abs(k - abs(a[i+1][j] - b[i+1][j]))] = true;
                    }

                    if (j+1 < w) {
                        dp[i][j+1][k + abs(a[i][j+1] - b[i][j+1])] = true;
                        dp[i][j+1][abs(k - abs(a[i][j+1] - b[i][j+1]))] = true;
                    }

                }
            }
        }
    }


    for (int i=0; i<=(h+w)*80; i++) {
        if (dp[h-1][w-1][i]) {
            cout << i << endl;
            return 0;
        }
    }
}