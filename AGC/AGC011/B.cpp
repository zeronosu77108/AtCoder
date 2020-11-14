#include <iostream>
#include <queue>

using namespace std;

using P = pair<long, long>;

int main() {
    long n;
    cin >> n;

    priority_queue<P, vector<P>, greater<>> pq;
    for (int i=0; i<n; i++) {
        long a;
        cin >> a;
        pq.emplace(a, 1);
    }

    long ans = n;
    while(pq.size() > 1) {
        auto [a1, c1] = pq.top(); pq.pop();
        const auto [a2, c2] = pq.top(); pq.pop();
        if (a1*2 < a2) ans -= c1, c1=0;
        pq.emplace(a1+a2, c1+c2);
    }

    cout << ans << endl;
}