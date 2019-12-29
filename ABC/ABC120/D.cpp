#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

struct unionfind {
  vector<long long> par;
  vector<long long> _size;

  // コンストラクタ
  unionfind(long n) : par(n+1), _size(n+1,1) {
    for(long long i=1; i<=n; i++) par[i]=i;
  }

  void init(long long n) {
    par = vector<long long>(n+1);
    _size = vector<long long>(n+1);
    for(long long i=1; i<=n; i++) par[i]=i;
  }

  long long root(long long x) {
    while (par[x] != x) {
      x = par[x] = par[par[x]];
    }
    return x;
  }

  bool merge(long long x, long long y) {
    x = root(x);
    y = root(y);
    if (x==y) return false;

    if(_size[x]<_size[y]) swap(x,y);

    _size[x] += _size[y];
    par[y] = x;
    return true;
  }

  bool issame(long long x, long long y) {
    return root(x) == root(y);
  }

  long long size(long long x) {
    return _size[root(x)];
  }
};

int main() {
  int n,m;
  cin >> n >> m;
  unionfind uni(n);
  vector<pair<long,long>> to;
  for (int i=0; i<m; i++) {
    int a,b;
    cin >> a >> b;
    to.push_back(make_pair(a,b));
  }
  reverse(to.begin(), to.end());

  vector<long long> ans;
  ans.push_back((long long)n*(n-1)/2);
  for (auto e : to) {
    // cerr << e.first << "->" << e.second << endl;
    long long a,b;
    a = uni.size(e.first);
    b = uni.size(e.second);
    if(uni.merge(e.first, e.second)) {
      ans.push_back(max(0LL, ans.back()-(long long)a*b));
    } else {
      ans.push_back(ans.back());
    }
  }
  ans.pop_back();

  for_each(ans.rbegin(), ans.rend(), [](const auto &i) {cout << i << endl;});
}