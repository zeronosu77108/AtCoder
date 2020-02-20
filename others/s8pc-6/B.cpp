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
    int64 n;
    cin >> n;
    vector<int64> a(n);
    vector<int64> b(n);
    for (int i=0; i<n; i++) cin >> a[i] >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
   
    int64 amedian = a[n/2];
    int64 bmedian = b[n/2];
    if (n % 2 == 0) {
        amedian = (amedian + a[n/2-1]) /2;
        bmedian = (bmedian + b[n/2-1]) /2;
    }
    



    int64 enter = 0;
    {
        int64 sum = LONG_MAX;
        for (int i=amedian-50; i<=amedian+50; i++) {
            int64 cnt = 0;
            for (int j=0; j<n; j++) { 
                cnt += abs(i - a[j]);
            }
            if (sum > cnt) {
                sum = cnt;
                enter = i;
            }
        }
    }


    int64 exit = 0;
    {
        int64 sum = LONG_MAX;
        for (int i=bmedian-50; i<=bmedian+50; i++) {
            int64 cnt = 0;
            for (int j=0; j<n; j++) { 
                cnt += abs(i - b[j]);
            }
            if (sum > cnt) {
                sum = cnt;
                exit = i;
            }
        }
    }

    int64 ans = 0;
    for (int i=0; i<n; i++) {
        ans += abs(enter - a[i]);
        ans += abs(a[i] - b[i]);
        ans += abs(b[i] - exit);
    }
    cout << ans << endl;
}
