#include <iostream>

using namespace std;

int main() {
    int n,t,a;
    cin >> n >> t >> a;
    
    int ans;
    long long s = LONG_MAX;
    for (int i=0; i<n; i++) {
        long long h;
        cin >> h;
        int tmp = abs(1000*a - (t*1000 - h*6));
        if (s > tmp) {
            ans = i+1;
            s = tmp;
        }
    }

    cout << ans << endl;
}
