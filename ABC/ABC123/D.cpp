#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <set>

using namespace std;

typedef pair<long, tuple<long,long,long>> P;

int main() {
  long x,y,z,k;
  long a;
  vector<vector<long>> cake(3);

  cin >> x >> y >> z >> k;

  for (int i=0; i<x; i++) {
    cin >> a;
    cake[0].push_back(a);
  }
  sort(cake[0].rbegin(), cake[0].rend());

  for (int i=0; i<y; i++) {
    cin >> a;
    cake[1].push_back(a);
  }
  sort(cake[1].rbegin(), cake[1].rend());

  for (int i=0; i<y; i++) {
    cin >> a;
    cake[2].push_back(a);
  }
  sort(cake[2].rbegin(), cake[2].rend());

  priority_queue<P> ans;
  set<tuple<long,long,long>> used;
  used.insert(make_tuple(0,0,0));
  ans.push(P(cake[0][0] + cake[1][0] + cake[2][0], make_tuple(0,0,0)));

  for (int i=0; i<k; i++) {
    cout << ans.top().first << endl;;
    int xi,yi,zi;
    tie(xi,yi,zi) = ans.top().second;
    ans.pop();

    tuple<long, long, long> t;
    if (x-1 >= xi+1) {

      t = make_tuple(xi+1, yi, zi);
      auto it = used.find(t);
      if (it == used.end()) {
        used.insert(t);
        ans.push(P( cake[0][xi+1]+cake[1][yi]+cake[2][zi], t));
      }
    }

    if (y-1 >= yi+1) {
      t = make_tuple(xi, yi+1, zi);
      auto it = used.find(t);
      if (it == used.end()) {
        used.insert(t);
        ans.push(P( cake[0][xi]+cake[1][yi+1]+cake[2][zi], t));
      }
    }

    if (z-1 >= zi+1) {
      t = make_tuple(xi, yi, zi+1);
      auto it = used.find(t);
      if (it == used.end()) {
        used.insert(t);
        ans.push(P( cake[0][xi]+cake[1][yi]+cake[2][zi+1], t));
      }
    }
  }

}