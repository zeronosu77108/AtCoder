#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> abc(3);
    int x;
    for (int i=0; i<3; i++) cin >> abc[i];
    cin >> x;
    sort(abc.begin(), abc.end());

    cout << abc[0] + abc[1] + abc[2] * (1<<x) << endl;
}