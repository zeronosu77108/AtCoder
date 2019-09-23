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
  string s;
  cin >> s;
  int n = s.size();
  sort(s.begin(), s.end());
  s.erase(unique(s.begin(),s.end()), s.end());
  cout << (n==s.size()? "yes" : "no") << endl;
}