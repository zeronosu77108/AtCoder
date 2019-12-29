#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <queue>

using namespace std;

typedef pair<long,long> P;

int main() {
  long n,m;
  long ans=0;
  cin >> n >> m;
  vector< vector<long> > jobs(m+1);

  for (int i=0; i<n; i++) {
    int a,b;
    cin >> a >> b;
    if(a>m) continue;
    jobs[a].push_back(b);
  }

  priority_queue<int> pq;
  for (int i=1; i<=m; i++) {
    for (auto j : jobs[i]) pq.push(j);

    if(pq.empty()) continue;

    ans += pq.top();
    pq.pop();
  }

  cout << ans << endl;
}