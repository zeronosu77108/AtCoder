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
  cin >> n;
  bool ans = false;

  for (int i=1; i<=9; i++) {
    if (n/i<=9 && n%i==0) ans = true;
  }

  cout << (ans? "Yes" : "No") << endl;
}