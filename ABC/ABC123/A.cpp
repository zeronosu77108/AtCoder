#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int main() {
  vector<int> point(5);
  int k;
  bool ans = true;

  for (int i=0; i<5; i++) cin >> point[i];
  cin >> k;

  for (int i=0; i<5; i++) {
    for (int j=i+1; j<5; j++) {
      if (abs(point[j] - point[i]) > k)
        ans = false;      
    }
  }

  cout << (ans? "Yay!" : ":(") << endl;
}