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
#include <climits>

using namespace std;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v){o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}
#define debug(v) {cerr<<"\033[1;36m[debug]\033[m "<<#v<<" : "<<v<<endl;}

// using int64 = long long;
typedef long long int64;


class BIT {
    int n;
    vector<int64> d;
public:
    BIT(int _n=0) {n=_n; d=vector<int64>(n+1);}
    void add(int i, int64 x=1) { for (i++; i <= n; i += i&-i) d[i] += x; }
    int64 sum(int i) { int64 x = 0; for (i++; i; i -= i&-i) x += d[i]; return x; }
};


int main() {
    int n;
    string s;
    cin >> n >> s;
    vector<BIT> bit(26, BIT(n));
    for (int i=0; i<n; i++) {
        bit[s[i] - 'a'].add(i,1);
    }

    int q;
    cin >> q;
    for (int i=0; i<q; i++) {
        int type; cin >> type;
        switch(type) {
            case 1:
                int i;
                char c;
                cin >> i >> c;
                bit[s[i-1] - 'a'].add(i-1,-1);
                bit[c - 'a'].add(i-1,1);
                s[i-1] = c;
                break;
            case 2:
                int l,r;
                cin >> l >> r;
                int ans = 0;
                for (int i=0; i<26; i++) {
                    if (bit[i].sum(r-1) - bit[i].sum(l-2) >= 1)
                        ans++;
                }
                cout << ans << endl;
                break;
        }
    }
}
