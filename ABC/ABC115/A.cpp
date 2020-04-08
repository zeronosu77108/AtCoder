#include <iostream>

using namespace std;

int main() {
    int d;
    cin >> d;
    string ans = "Christmas";
    for (int i=25; i>d; i--) ans += " Eve";

    cout << ans << endl;
}
