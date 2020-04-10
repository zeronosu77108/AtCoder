#include <iostream>
#include <vector>

using namespace std;

int main() {
    int a,b,k;
    cin >> a >> b >> k;
    vector<int> ans;
    for (int i=1; i<10000; i++) {
        if (a%i == 0 && b%i == 0) ans.push_back(i);
    }

    cout << *(ans.end()-k) << endl;
}
