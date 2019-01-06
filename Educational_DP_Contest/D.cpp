#include <iostream>
#include <algorithm>

using namespace std;

long long N,W;
long long weight[1110], value[110];

long long dp[110][10010];

void printDpTable() {
    for (int i=0; i<=N; i++) {
        for (int j=0; j<=W; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}

int main(void) {

    cin >> N >> W;
    for (int i=0; i<N; i++) cin >> weight[i] >> value[i];

    for (int i=0; i<N; i++) {
        for (int w=0; w<=W; w++) {
            if( w>= weight[i]) {
                dp[i+1][w] = max(dp[i][w - weight[i]] + value[i], dp[i][w]);
            } else {
                dp[i+1][w] = dp[i][w];
            }
        }
    }

    // printDpTable();
    cout << dp[N][W] << endl;
}
