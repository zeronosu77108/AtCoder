#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <numeric>
#include <set>
#include <unordered_map>

using namespace std;
struct aaa{aaa(){cin.tie(nullptr); ios::sync_with_stdio(false); cout<<fixed<<setprecision(20);};}aaa;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v){o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}
#define debug(v) {cerr<<"\033[1;36m[debug]\033[m "<<#v<<" : "<<v<<endl;}

using int64 = long long;

long long tol(const string& s) {
    long long buf = 1e9;
    long long res = 0;
    bool f = false;
    for (auto c : s) {
        if (c == '.') {
            f = true;
            continue;
        }
        if (f) buf/=10;
        res *= 10;
        res += (c - '0');
    }
    return res * buf;
}

int main() {
    int n;
    cin >> n;
    vector a(n,0LL);
    for (int i=0; i<n; i++) {
        string b;
        cin >> b;
        a[i] = tol(b);
    }

    vector cnt(19, vector(19, 0LL));
    int64 ans = 0;
    for (int i=0; i<n; i++) {
        int _2 = 0;
        while(a[i]!=0 && a[i]%2==0) a[i]/=2, _2++;
        int _5 = 0;
        while(a[i]!=0 && a[i]%5==0) a[i]/=5, _5++;

        for (int k=max(0, 18-_2); k<=18; k++) {
            for (int l=max(0, 18-_5); l<=18; l++) {
                ans += cnt[k][l];
            }
        }

        cnt[min(18, _2)][min(18, _5)]++;
    }

    cout << ans << endl;
}
