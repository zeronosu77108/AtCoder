#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

typedef pair<int,int> P;

int main() {
    int n;
    bool ans = false;
    cin >> n;
    vector<P> p(n);
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
        p[i].second = a[i];
    }

    for (int i=0; i<n; i++) cin>>p[i].first;
    sort(p.begin(), p.end());
    sort(a.begin(), a.end());

    for (int i=0; i<n; i++) {
        if (a[i] > p[i].first) {
            puts("No");
            return 0;
        }
    }


    for (int i=0; i<n-1; i++)
        if (a[i+1] <= p[i].first) ans = true;

    map<int,int> trans;
    for (int i=0; i<n; i++) trans[p[i].second] = i;

    int i=0;
    vector<bool> used(n,false);
    int cnt = 0;
    while (!used[i]) {
        used[i] = true;
        i = trans[a[i]];
        cnt++;
    }
    if (cnt != n) ans = true;

    cout << (ans? "Yes" : "No") << endl;
}