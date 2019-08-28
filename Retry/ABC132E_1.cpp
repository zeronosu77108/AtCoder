#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

typedef pair<long,long> P;

void bfs(queue<P>& q, vector<vector<int>>&to, vector<vector<int>>& ans) {
  while( !q.empty()) {
    P p = q.front();
    int u = p.first;
    int c = p.second;
    q.pop();

    for (auto v : to[u]) {
      if(ans[c%3][v]!=-1) continue;
      // cout << u << "->" << v << endl;
      ans[c%3][v] = c;
      q.push(P(v,c+1));
    }
  }
}

int main() {
  long n,m;
  long s,t;
  cin >> n >> m;
  vector<vector<int>> to(n+1);
  vector<vector<int>> ans(3, vector<int>(n+1, -1));

  for (long i=0; i<m; i++) {
    int u,v;
    cin >> u >> v;
    to[u].push_back(v);
  }

  cin >> s >> t;

  queue<P> q;
  q.push(P(s,1));

  bfs(q,to,ans);

  if(ans[0][t] >= 0) ans[0][t]/=3;

  cout << ans[0][t] << endl;
}