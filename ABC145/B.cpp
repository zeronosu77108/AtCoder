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
    string s;
    cin >> n >> s;

    if (n % 2 == 1) {
        cout << "No" << endl;
        return 0;
    }

    if (s.substr(0,n/2) == s.substr(n/2, n/2)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}