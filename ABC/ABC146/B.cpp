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
    string s;
    cin >> n >> s;

    for (auto c : s) {
        cout << (char)((((c-'A') + n) % 26) + 'A');
    }
    cout << endl;
}