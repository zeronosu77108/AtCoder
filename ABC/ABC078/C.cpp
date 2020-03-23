#include <iostream>

using namespace std;
using int64 = long long;

const long double eps = 1e-10;
int main() {
    int n,m;
    cin >> n >> m;
    int64 ans = 100*(n-m) + 1900*m;
    for (int i=0; i<m; i++) ans*=2;
    cout << ans << endl;
}

/*
 * x = (100 * (n-m) + 1900 * m) * (1/2)^m …
 *
 */