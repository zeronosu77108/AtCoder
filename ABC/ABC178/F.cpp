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

using namespace std;
struct aaa{aaa(){cin.tie(nullptr); ios::sync_with_stdio(false); cout<<fixed<<setprecision(20);};}aaa;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v){o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}
#define debug(v) {cerr<<"\033[1;36m[debug]\033[m "<<#v<<" : "<<v<<endl;}

using int64 = long long;

int main() {
    int n;
    cin >> n;
    vector a(n,0);
    vector b(n,0);
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<n; i++) cin >> b[i];
    sort(b.rbegin(), b.rend());
//    debug(a);
//    debug(b);

    bool ans = true;

    for (int i=0; i<100; i++) {
        int front = 0;
        int back = n-1;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == b[i]) {
                cnt++;
                if (b[front] != b[i]) {
                    swap(b[front], b[i]);
                    front++;
                } else if (b[back] != b[i]) {
                    swap(b[back], b[i]);
                    back--;
                }
            }
        }
    }

    for (int i=0; i<n; i++) {
        if (a[i] == b[i]) ans = false;
    }

    if (ans) {
        cout << "Yes" << endl;
        for (int i=0; i<n; i++) {
            cout << b[i] << (i==n-1? "\n" : " ");
        }
    } else {
        cout << "No" << endl;
    }
}