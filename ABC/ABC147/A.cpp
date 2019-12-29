#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int main() {
    int a1,a2,a3;
    cin >> a1 >> a2 >> a3;

    cout << (a1+a2+a3>=22? "bust" : "win") << endl;
}