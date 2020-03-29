#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<char> s(n);
    for (int i=0; i<n; i++) cin >> s[i];
    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end());
    if (s.size() == 3) {
        cout << "Three" << endl;
    } else {
        cout << "Four" << endl;
    }
}