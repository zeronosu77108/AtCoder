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
    string s;
    cin >> s;

    bool f1 = s.size() % 2 == 0;
    bool f2 = s[0] == s.back();

    cout << (f1 ^ f2? "Second" : "First") << endl;
}
/*
 * aba -> 先手が負け
 * acba -> 後手
 * abcda -> 先手
 * abcba -> 先手
 * abc -> 後手
 * abcd -> 先手
 *
 * 偶数 かつ 前後が同じ   -> 後手
 * 偶数 かつ 前後が異なる -> 先手
 * 奇数 かつ 前後が同じ  -> 後手
 * 奇数 かつ 前後が異なる -> 先手
 */