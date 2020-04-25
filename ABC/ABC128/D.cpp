#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int n,k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i=0; i<n; i++) cin >> v[i];

    int ans = 0;
    for (int i=0; i<=k; i++) {
        for (int j=0; j<=k; j++) {
            if (i+j > n || i+j > k) continue;
            int sum = 0;
            priority_queue<int,vector<int>,greater<>> pq;
            for (int l=0; l<i; l++) {
                sum += v[l];
                if (v[l] < 0) pq.emplace(v[l]);
            }
            for (int l=0; l<j; l++) {
                sum += v[n-1-l];
                if (v[n-1-l] < 0) pq.emplace(v[n-1-l]);
            }

            for (int l=i+j; l<k; l++) {
                if(pq.empty()) break;
                sum -= pq.top(); pq.pop();
            }
            ans = max(ans, sum);
        }
    }

    cout << ans << endl;
}