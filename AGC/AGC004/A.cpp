#include <iostream>

using namespace std;
using int64 = long long;

int main() {
    int64 a,b,c;
    cin >> a >> b >> c;
    
    int64 ans = LONG_MAX;
    ans = min(ans, abs(a*b*(c/2) - a*b*((c+1)/2)));
    ans = min(ans, abs(a*c*(b/2) - a*c*((b+1)/2)));
    ans = min(ans, abs(b*c*(a/2) - b*c*((a+1)/2)));
    cout << ans << endl;
    return 0;
}
