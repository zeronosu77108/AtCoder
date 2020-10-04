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

int main() {
    int n;
    string s;
    cin >> n >> s;

    vector<int> acsum(n+1, 0);
    for (int i=0; i<n; i++) acsum[i+1] = acsum[i] + (s[i] == 'A');

    vector<int> gcsum(n+1, 0);
    for (int i=0; i<n; i++) gcsum[i+1] = gcsum[i] + (s[i] == 'G');

    vector<int> ccsum(n+1, 0);
    for (int i=0; i<n; i++) ccsum[i+1] = ccsum[i] + (s[i] == 'C');

    vector<int> tcsum(n+1, 0);
    for (int i=0; i<n; i++) tcsum[i+1] = tcsum[i] + (s[i] == 'T');

    int64 ans = 0;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if (acsum[j+1]-acsum[i] != tcsum[j+1]-tcsum[i]) continue;
            if (gcsum[j+1]-gcsum[i] != ccsum[j+1]-ccsum[i]) continue;
            ans++;
        }
    }

    cout << ans << endl;
}