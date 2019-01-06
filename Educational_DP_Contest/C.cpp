#include <iostream>
#include <algorithm>

using namespace std;

int n;
int h[10010][3];

long long dp[100010][3];
void printDpTable();

int main(void) {
    cin >> n;

    for (int i=0; i<n; i++) 
        for (int j=0; j<3; j++)
            cin >> h[i][j];

    dp[0][0] = h[0][0];
    dp[0][1] = h[0][1];
    dp[0][2] = h[0][2];


    for (int i=0; i<=n; i++) {
        for (int j=0; j<3; j++) {
            int tmp[3] = {dp[i][0] + h[i+1][j], dp[i][1] + h[i+1][j], dp[i][2] + h[i+1][j]};
            tmp[j] = 0;
            dp[i+1][j] = max({ tmp[0], tmp[1], tmp[2] });
        }
    }

    // cout << endl;
    // printDpTable();

    cout << max({dp[n][0], dp[n][1], dp[n][2]}) << endl;
}

void printDpTable() {
    for (int i=0; i<=n; i++) {
        for (int j=0; j<3; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}
