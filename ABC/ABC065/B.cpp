#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<int> a(n+1);
    for (int i=1; i<=n; i++) cin >> a[i];

    vector<bool> used(n+1,false);
    int current = 1;
    while(!used[current]) {
        used[current] = true;
        current = a[current];
        if (current == 2) break;
    }


    int ans = count(used.begin(), used.end(), true);
    if (current != 2) ans = -1;

    cout << ans << endl;
}