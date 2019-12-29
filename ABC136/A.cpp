#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int main() {
  int a,b,c;
  cin >> a >> b >> c;
  int ans = c - (a-b);
  cout << (ans>=0? ans : 0) << endl;
}