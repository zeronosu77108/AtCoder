#include <iostream>

using namespace std;

int main() {
    int a,b;
    cin >> a >> b;
    if (a<=0 && 0<=b) {
        cout << "Zero" << endl;
        return 0;
    }

    bool p = true;
    if (b<0 && abs(b-a)%2==0) p = false;
    cout << (p? "Positive" : "Negative") << endl;
}
