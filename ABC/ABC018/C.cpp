#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <numeric>

using namespace std;
struct aaa{aaa(){cin.tie(nullptr); ios::sync_with_stdio(false); cout<<fixed<<setprecision(20);};}aaa;

typedef long long int64;


int main() {
    int r,c,k;
    int64 ans = 0;
    cin >> r >> c >> k;
    vector<string> s(r);
    for (int i=0; i<r; i++) cin>>s[i];


    vector<vector<int>> top(r, vector<int>(c,0));
    vector<vector<int>> buttom(r, vector<int>(c,0));

    for (int i=0; i<c; i++) {
        top[0][i] = s[0][i] == 'o';
        buttom[r-1][i] = s[r-1][i] == 'o';
    }
    for (int j=0; j<c; j++) {
        for (int i=1; i<r; i++) {
            if (s[i][j] == 'o') top[i][j] = top[i-1][j] + 1;
            else top[i][j] = 0;
        }
    }
    for (int j=0; j<c; j++) {
        for (int i=r-2; i>=0; i--) {
            if (s[i][j] == 'o') buttom[i][j] = buttom[i+1][j] + 1;
            else buttom[i][j] = 0;
        }
    }


    for (int i=k-1; i<r; i++) {
        for (int j=k-1; j<c; j++) {
            bool f = true;
            for (int l=(-k+1); l<k; l++) {
                if (j + l < 0 || j + l >= c) {
                    f = false;
                    break;
                }
                if (top[i][j+l] < k - abs(l) || buttom[i][j+l] < k -abs(l)) f = false;
            }
            if (f) ans++;
        }
    }



    cout << ans << endl;
    return 0;
}