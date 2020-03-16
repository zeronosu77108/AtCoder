#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n,k;
    cin >> n >> k;

    bool ans = k <= n/2;
    cout << (ans? "YES" : "NO") << endl;
}