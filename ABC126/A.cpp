#include <iostream>

using namespace std;

int main(void) {
    int n,k;
    char c;
    cin >> n >> k;

    for (int i=1; i<=n; i++) {
        cin >> c;
        if ( k == i ) {
            c = tolower(c);
        }
        cout << c;
    }
    cout << endl;
}
