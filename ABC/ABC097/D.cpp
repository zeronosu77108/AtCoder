#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>
#include <set>

using namespace std;

struct unionfind {
  vector<long long> par,_size;
  unionfind(long n) : par(n), _size(n,1) { // コンストラクタ
    for(long long i=0; i<n; i++) par[i]=i;
  }
  void init(long long n) {
    par = vector<long long>(n);
    _size = vector<long long>(n);
    for(long long i=0; i<n; i++) par[i]=i;
  }
  long long root(long long x) {
    while (par[x] != x) x = par[x] = par[par[x]];
    return x;
  }
  bool merge(long long x, long long y) {
    x=root(x); y=root(y);
    if (x==y) return false;
    if(_size[x]<_size[y]) swap(x,y);
    _size[x] += _size[y];
    par[y] = x;
    return true;
  }
  bool issame(long long x, long long y) { return root(x) == root(y); }
  long long size(long long x) { return _size[root(x)]; }
};

int main() {
  int n,m;
  int ans = 0;
  cin >> n >> m;
  vector<int> p(n+1);
  for (int i=1; i<=n; i++) cin>>p[i];

  unionfind uni(n+1);

  for (int i=0; i<m; i++) {
    int x,y;
    cin >> x >> y;
    uni.merge(x,y);
  }

  for (int i=1; i<=n; i++) {
    if (p[i] == i || uni.issame(i,p[i]) ) ans++;
  }

  cout << ans << endl;
}