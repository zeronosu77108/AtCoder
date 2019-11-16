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
    cout << max(a+b, max(a-b, a*b)) << endl;
}