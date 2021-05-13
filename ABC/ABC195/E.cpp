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


template <class T>ostream &operator<<(ostream &o, const optional<T>&v){o << (v ? to_string(v.value()) : "-");return o;}
template <class T>ostream &operator<<(ostream &o,const vector<T>&v){o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}
#define debug(v) {cerr<<"\033[1;36m[debug]\033[m "<<#v<<" : "<<(v)<<endl;}

using int64 = long long;

int dfs(int i, int y , int n, const string& s, const string& x,  vector<vector<optional<bool>>>& memo) {
    if (memo[y][i]) return memo[y][i].value();

    const int zero = y*10 % 7;
    const int add = (y*10 + (s[i]-'0')) % 7;

    if (i+1 == n) {
        if (x[i] == 'A') memo[y][i] = add == 0 && zero == 0; // どちらも 7の倍数なら高橋勝ち
        else memo[y][i] = add == 0 || zero == 0; // どちらかが 7の倍数なら高橋勝ち

        return memo[y][i].value();
    }


    if (x[i] == 'A') {
        bool f = dfs(i+1, add, n, s, x, memo) && dfs(i+1, zero, n, s, x, memo); // 両方 true なら 高橋勝ち
        memo[y][i] = f;
    } else {
        bool f = dfs(i+1, add, n, s, x, memo) || dfs(i+1, zero, n, s, x, memo); // 片方が true なら 高橋勝ち
        memo[y][i] = f;
    }
    return memo[y][i].value();
}


int main() {
    int n;
    string s, x;
    cin >> n >> s >> x;

    vector memo(7, vector(n+1, optional<bool>()));
    cout << (dfs(0,0,n,s,x,memo)? "Takahashi" : "Aoki") << endl;
}

