#include <iostream>
#include <utility>
#include <vector>
#include <map>

using namespace std;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    vector<int> a1;
    vector<int> a2;
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        if (i%2==0) a1.push_back(a);
        else a2.push_back(a);
    }

    sort(a1.begin(), a1.end());
    sort(a2.begin(), a2.end());

    vector<P> al1;
    al1.emplace_back(0, -1);
    al1.emplace_back(0, a1[0]);
    for (int i=0; i<n/2; i++) {
        if (al1.back().second == a1[i]) al1.back().first++;
        else al1.emplace_back(1, a1[i]);
    }

    vector<P> al2;
    al2.emplace_back(0, -1);
    al2.emplace_back(0, a2[0]);
    for (int i=0; i<n/2; i++) {
        if (al2.back().second == a2[i]) al2.back().first++;
        else al2.emplace_back(1, a2[i]);
    }

    sort(al1.rbegin(), al1.rend());
    sort(al2.rbegin(), al2.rend());

    int ans = 0;
    if (al1[0].second == al2[0].second) {
        int _1 = (n/2 - al1[0].first) + (n/2 - al2[1].first);
        int _2 = (n/2 - al1[1].first) + (n/2 - al2[0].first);
        ans = min(_1, _2);
    } else {
        ans = (n/2 - al1[0].first) + (n/2 - al2[0].first);
    }

    cout << ans << endl;
}