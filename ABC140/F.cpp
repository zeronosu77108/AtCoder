#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

typedef pair<int, int> P;

bool add_queue(const int s1, queue<P>& q, vector<int>& s) {
    auto it = lower_bound(s.begin(), s.end(), s1);
    if (it == s.begin()) return false;
    it--;
    // cout << s1 << " " << *it << endl;
    q.push(P(s1, *it));
    s.erase(it);
    return true;
}

int main() {
    int n;
    cin >> n;

    int ns = pow(2, n);
    vector<int> s(ns);
    for (int i=0; i<ns; i++) cin >> s[i];
    sort(s.begin(), s.end());

    int s1, s2;
    s2 = s.back();
    s.pop_back();
    s1 = s.back();
    s.pop_back();
    
    bool ans = true;
    queue<P> q;
    if (s1 < s2) q.push(P(s1, s2));
    else ans = false;

    int day = 0;
    while (true) {
        if (q.empty()) break;
        queue<P> next_q;
        day++;
        while (!q.empty()) {
            P p = q.front();
            q.pop();
            s1 = p.first;
            s2 = p.second;

            // if (!add_queue(s1, q, s) && !add_queue(s2, q, s)) break;
            add_queue(s1, next_q, s);
            add_queue(s2, next_q, s);
        }
        q = next_q;
    }

    ans = ans && q.empty() && s.size()<=0 && day <= n;
    cout << (ans?"Yes":"No") << endl;
}

