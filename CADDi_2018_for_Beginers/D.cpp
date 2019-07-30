#include <iostream>
#include <string>

using namespace std;

int main(void) {
    int n;
    string winner = "second";
    cin >> n;
    

    for(int i=0; i<n; i++) {
        int a;
        cin >> a;
        if ( a % 2 != 0 ) {
            winner = "first";
        }
    }
    cout << winner << endl;
} 
