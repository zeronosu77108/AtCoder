#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int s;
    cin >> s;
    int ans = INT_MAX;
    
    while(s!=0) {
        ans = min(ans, abs(753 - s%1000));
        s /= 10;
    }

    cout << ans << endl;
}
