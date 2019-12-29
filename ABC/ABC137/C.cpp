#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int main() {
  int n;
  long ans=0;
  cin >> n;
  map<string, int> ex;

  for (int i=0; i<n; i++) {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    if (ex[s]) ans+=ex[s];
    ex[s]++;
  }

  cout << ans << endl;
}