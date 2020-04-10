#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> cnt(2,0);

    for (int i=0; i<n; i++) {
        cnt[s[i]%2]++;
    }

    cout << 2*min(cnt[0], cnt[1]) << endl;
}
    
