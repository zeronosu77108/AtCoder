#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int main() {
    int r;
    cin >> r;
    string ans = "AGC";

    if (r < 1200) ans="ABC";
    else if (r < 2800) ans = "ARC";

    cout << ans << endl;
}