#include <iostream>

using namespace std;

int dsum(int n) {
    int res = 0;
    while(n != 0) {
        res += n % 10;
        n /= 10;
    }
    return res;
}

int main() {
    int n,a,b;
    cin >> n >> a >> b;

    int ans = 0;
    for (int i=1; i<=n; i++) {
        int _dsum = dsum(i);
        if (a <= _dsum && _dsum <= b) ans+= i;
    }
    cout << ans << endl;
}