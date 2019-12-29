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
  string ans;
  cin >> s;
  if (s == "Sunny") ans = "Cloudy";
  if (s == "Cloudy") ans = "Rainy";
  if (s == "Rainy") ans = "Sunny";

  cout << ans << endl;
}