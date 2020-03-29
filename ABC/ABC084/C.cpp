#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> c(n-1);
    vector<int> s(n-1);
    vector<int> f(n-1);

    for (int i=0; i<n-1; i++)
        cin >> c[i] >> s[i] >> f[i];

    for (int i=0; i<n; i++) {
        int ans = 0;
        int now = 0;
        for (int j=i; j<n-1; j++) {
            if (now < s[j]) now = s[j];
            if (now % f[j] != 0) {
                now += f[j] - (now % f[j]);
            }
            now += c[j];
        }
        cout << now << endl;
    }
}