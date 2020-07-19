#include <iostream>
#include <string>

using namespace std;

using int64 = long;

int main() {
    string s;
    cin >> s;
    int n = s.size();

    int64 ans = 0;
    int r = 0;
    for (int l=0; l<n; l++) {
        if (s[l] != '2' || l+1>=n || s[l+1] != '5') continue;
        if (l >= r) r = l + 1;
        while(r+2<n && s[r+1]=='2' && s[r+2]=='5') r+=2;
        if (r>=n) break;
        ans += (r-l+1)/2;
        cerr<<l<<" "<<r<<" "<<ans<<endl;
        l++;
    }

    cout << ans << endl;
}