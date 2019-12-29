#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int main() {
  int a,b;
  cin >> a >> b;
  if (a+b>=10) cout << "error";
  if (a+b<10) cout << a+b;
  cout << endl;
}