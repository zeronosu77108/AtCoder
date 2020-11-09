#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <numeric>
#include <set>
#include <complex>

using namespace std;
struct aaa{aaa(){cin.tie(nullptr); ios::sync_with_stdio(false); cout<<fixed<<setprecision(20);};}aaa;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v){o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}
#define debug(v) {cerr<<"\033[1;36m[debug]\033[m "<<#v<<" : "<<(v)<<endl;}

using int64 = long long;

int main() {
    int h, w, n, m;
    cin >> h >> w >> n >> m;

    vector s(h, vector(w, 0));

    for (int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        s[a][b] = 1;
    }

    for (int i=0; i<m; i++) {
        int c, d;
        cin >> c >> d;
        c--; d--;
        s[c][d] = -1;
    }

    vector up(h, vector(w, false));
    for (int i=w-1; i>=0; i--) {
        bool f = false;
        for (int j=h-1; j>=0; j--) {
            if (s[j][i] == 1) f = true, up[j][i]=true;
            else if (s[j][i] == -1) f = false;
            else up[j][i] = f;
        }
    }

    vector down(h, vector(w, false));
    for (int i=0; i<w; i++) {
        bool f = false;
        for (int j=0; j<h; j++) {
            if (s[j][i] == 1) f = true, down[j][i]=true;
            else if (s[j][i] == -1) f = false;
            else down[j][i] = f;
        }
    }


    vector left(h, vector(w, false));
    for (int j=0; j<h; j++) {
        bool f = false;
        for (int i=0; i<w; i++) {
            if (s[j][i] == 1) f=true, left[j][i]=true;
            else if (s[j][i] == -1) f = false;
            else left[j][i] = f;
        }
    }

    vector right(h, vector(w, false));
    for (int j=h-1; j>=0; j--) {
        bool f = false;
        for (int i=w-1; i>=0; i--) {
            if (s[j][i] == 1) f = true, right[j][i]=true;
            else if (s[j][i] == -1) f = false;
            else right[j][i] = f;
        }
    }



    int ans = 0;
    for (int i=0; i<h; i++) {
       for (int j=0; j<w; j++) {
           if (s[i][j] == -1) continue;
           if (up[i][j] || down[i][j] || left[i][j] || right[i][j]) ans++;
       }
    }
    cout << ans << endl;
}