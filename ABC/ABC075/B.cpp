#include <iostream>
#include <vector>

using namespace std;

int main() {
    int h,w;
    cin >> h >> w;
    vector<string> s(h);
    for (int i=0; i<h; i++) cin >> s[i];

    const vector<int> dx = {-1, 0, 1,-1, 1,-1, 0, 1};
    const vector<int> dy = { 1, 1, 1, 0, 0,-1,-1,-1};

    vector<string> ans(h, string(w,'#'));
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            if (s[i][j] == '#') continue;

            int cnt = 0;
            for (int k=0; k<8; k++) {
                int y = i + dy[k];
                int x = j + dx[k];
                if (y < 0 || h <= y) continue;
                if (x < 0 || w <= x) continue;
                if (s[y][x] == '#') cnt++;
            }
            ans[i][j] = char('0' + cnt);
        }
    }

    for (const auto& a : ans) {
        cout << a << endl;
    }
}