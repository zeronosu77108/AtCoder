//
// Created by zeronosu77108 on Mar 13, 2021.
//
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
#include <optional>

using namespace std;
struct aaa{aaa(){cin.tie(nullptr); ios::sync_with_stdio(false); cout<<fixed<<setprecision(20);};}aaa;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v){o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}
#define debug(v) {cerr<<"\033[1;36m[debug]\033[m "<<#v<<" : "<<(v)<<endl;}

using int64 = long long;

int main() {
    long k;
    string s,t;
    cin >> k >> s >> t;
    s.pop_back(); t.pop_back();

    vector cnt(10, k);
    for (int i=0; i<4; i++) cnt[s[i] - '0']--;
    for (int i=0; i<4; i++) cnt[t[i] - '0']--;

    const auto score = [](string s) {
        vector cnt(10, 0LL);
        for (const auto& c : s) cnt[c - '0']++;
        int64 res = 0;
        for (int i=0; i<10; i++) res += i * round(pow(10, cnt[i]));
        return res;
    };

    int64 win = 0;
    int64 all = 0;

    for (int i=1; i<10; i++) {
        if (cnt[i] <= 0) continue; cnt[i]--;
        for (int j=1; j<10; j++) {
            if (cnt[j] <= 0) continue;

            s += '0' + i;
            t += '0' + j;
            if (score(s) > score(t)) win += (cnt[i]+1) * cnt[j];
            all += (cnt[i]+1) * cnt[j];
            s.pop_back(); t.pop_back();
        }
        cnt[i]++;
    }


    cout << win / (double)all << endl;
}