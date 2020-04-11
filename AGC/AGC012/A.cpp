#include <iostream>
#include <vector>
#include <deque>

using namespace std;
using int64 = long long;

int main() {
    int n;
    cin >> n;
    vector<int64> a(3*n);
    for (int i=0; i<3*n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    deque<int64> deq;
    for (auto ai : a) deq.push_back(ai);

    int64 ans = 0;
    while(!deq.empty()) {
        int64 sum = 0;
        int64 _max = -1;
        int64 _min = INT_MAX;
        sum += deq.back();
        _max = max(_max, deq.back());
        _min = min(_min, deq.back());
        deq.pop_back();
        sum += deq.back();
        _max = max(_max, deq.back());
        _min = min(_min, deq.back());
        deq.pop_back();
        sum += deq.front();
        _max = max(_max, deq.front());
        _min = min(_min, deq.front());
        deq.pop_front();
        ans += sum - _max - _min;
    }

    cout << ans << endl;
}
