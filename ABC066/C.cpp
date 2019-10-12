#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  deque<int> ans;

  for (int i=0; i<n; i++) {
    int a; cin>>a;
    if (i%2 != n%2) ans.push_front(a);
    else ans.push_back(a);
  }

  while (!ans.empty()) {
    cout << ans.front();
    ans.pop_front();
    cout << (ans.empty()? '\n' : ' ');
  }
}