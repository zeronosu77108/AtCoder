#include <iostream>
#include <vector>
#include <string>

using namespace std;

const vector<int> dx = {-1, +0, +0, +1, +0};
const vector<int> dy = {+0, +1, +0, +0, -1};

void fill(const int& y, const int& x, const int& h, const int& w, const vector<string>& s, vector<string>& t) {
    int cnt = 0;
    for (int i=0; i<5; i++) {
        int xi = x + dx[i];
        int yi = y + dy[i];
        if (xi < 0 || w <= xi) continue;
        if (yi < 0 || h <= yi) continue;
        if (s[yi][xi] == '#') cnt++;
    }

    if (cnt < 2) return;

    for (int i=0; i<5; i++) {
        int xi = x + dx[i];
        int yi = y + dy[i];
        if (xi < 0 || w <= xi) continue;
        if (yi < 0 || h <= yi) continue;
        if (s[yi][xi] == '#')
            t[yi][xi] = '#';
    }
}

int main() {
    int h,w;
    cin >> h >> w;
    vector<string> s(h);
    for (int i=0; i<h; i++) cin >> s[i];

    vector<string> t(h, string(w,'.'));
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            if (s[i][j] == '#') {
                fill(i,j,h,w,s,t);
            }
        }
    }

    bool ans = s == t;
    cout << (ans? "Yes" : "No") << endl;
}