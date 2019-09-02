#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <deque>
#include <cmath>
#include <string>

using namespace std;

typedef pair<int,int> P;

void addGame(int a1, const vector<queue<int>>& a, const int day, queue<tuple<int,int,int>>& q) {
  if (a[a1].empty()) return;
  int a2 = a[a1].front();
  if (a1 == a[a2].front()) q.push( make_tuple(a1,a2,day));
}

int main() {
  int n;
  int ans = 0;
  cin >> n;

  vector<queue<int>> a(n+1);

  for (int i=1; i<n+1; i++) {
    for (int j=0; j<n-1; j++) {
      int ai;
      cin >> ai;
      a[i].push(ai);
    }
  }

  queue<tuple<int,int,int>> games;

  vector<bool> used(n+1,false);
  for (int i=1; i<n+1; i++) {
    if (used[i]) continue;
    int j = a[i].front();
    if (i == a[j].front()) {
      used[i]=true; used[j]=true;
      games.push(make_tuple(i,j,1));
    }
  }

  while(!games.empty()) {
    int a1,a2,day;
    tie(a1,a2,day) = games.front();
    ans = max(ans, day);
    games.pop();

    a[a1].pop();
    a[a2].pop();

    addGame(a1,a,day+1,games);
    addGame(a2,a,day+1,games);
  }


  for (auto ai : a) {
    if (ai.size() > 0 ) {
      ans = -1;
      break;
    }
  }
  cout << ans << endl;

}
