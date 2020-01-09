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

vector<int> dx8 = {-1, 0, 1,-1, 0, 1,-1, 0, 1};
vector<int> dy8 = {-1,-1,-1, 0, 0, 0, 1, 1, 1};

int main() {
    int h,w;
    cin >> h >> w;
    vector<string> s(h);
    for (int i=0; i<h; i++) cin >> s[i];
    vector<string> ans(h, string(w,'#'));

    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            if (s[i][j] == '.') {
                for (int k=0; k<9; k++) {
                    int yi = i + dy8[k];
                    int xi = j + dx8[k];
                    if (xi < 0 || w <= xi) continue;
                    if (yi < 0 || h <= yi) continue;
                    ans[yi][xi] = '.';
                }
            }
        }
    }

    vector<string> tmp(h, string(w,'.'));
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            if (ans[i][j] == '#') {
                for (int k=0; k<9; k++) {
                    int yi = i + dy8[k];
                    int xi = j + dx8[k];
                    if (xi < 0 || w <= xi) continue;
                    if (yi < 0 || h <= yi) continue;
                    tmp[yi][xi] = '#';
                }
            }
        }
    }


    if (tmp != s) {
        cout << "impossible" << endl;
        return 0;
    }
    cout << "possible" << endl;
    for (auto a : ans) cout << a << endl;
}