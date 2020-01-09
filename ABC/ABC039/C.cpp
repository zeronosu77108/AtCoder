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

vector<string> ans = {"Do", "Do", "Re", "Re", "Mi", "Fa", "Fa", "So", "So", "La", "La", "Si"};
//vector<string> ans = {"Mi", "Re", "Re", "Do", "Do", "Si", "La", "La", "So", "So", "Fa", "Fa", "Mi"};

int main() {
    string s;
    cin >> s;
    int n = s.size();

    vector<string> key(n);

    int w,ww;
    w = ww = -1;
    for (int i=0; i<n; i++) {
        if (w == -1 && s[i] == s[i+1]) w = i;
        else if (s[i] == s[i+1]) {
            ww = i;
            break;
        }
    }

    if (ww - w == 7) {
        key[0] = ans[(12 - ww - 1) % 12];
    } else {
        key[0] = ans[(12 - w - 1) % 12];
    }


    cout << key[0] << endl;
}