#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>


using namespace std;

int main(void) {
    char c1,c2;
    c2 = '-';
    bool f = false;
    for(int i=0; i<4; i++) {
        cin >> c1;

        if ( f || c1 == c2 ) {
            f = true;
        }
        c2 = c1;
    }

    cout << (f? "Bad" : "Good") << endl;
}
