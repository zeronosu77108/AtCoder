#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector ans(2*n-1, -1);

    if (x==1 || x==2*n-1) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;

    set<int> s;
    for (int i=1; i<2*n; i++) s.insert(i);
    ans[n-1] = x;
    ans[n-2] = x-1;
    ans[n] = x+1;
    s.erase(x);
    s.erase(x-1);
    s.erase(x+1);


    if (n>=3) {
        if (x >= 3) {
            ans[n + 1] = 1;
            s.erase(1);
        } else {
            ans[n - 3] = 2*n-1;
            s.erase(2*n-1);
        };
    }

    for (int i=0; i<2*n-1; i++) {
        if (ans[i] > 0) continue;
        ans[i] = *s.rbegin();
        s.erase(*s.rbegin());
    }
    for (auto an : ans) cout << an << endl;
}