#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <numeric>

using namespace std;
struct aaa{aaa(){cin.tie(nullptr); ios::sync_with_stdio(false); cout<<fixed<<setprecision(20);};}aaa;

typedef long long int64;
typedef pair<int64,int64> P;


int main() {
    int n,k;
    cin >> n >> k;
    vector<int> w(n);
    vector<int> p(n);


    for (int i=0; i<n; i++) cin >> w[i] >> p[i];

    double l = 0;
    double r = 100;

    while(r-l > 1e-10) {
        double g = (l+r)/2;
        priority_queue<double> pq;
        for (int i=0; i<n; i++) pq.emplace(w[i]*(p[i]-g)*100.0);

        double sum = 0;
        for (int i=0; i<k; i++) {
            sum += pq.top(); pq.pop();
        }

        if (sum > 0) l = g;
        else r = g;
    }

    cout << l << endl;
}