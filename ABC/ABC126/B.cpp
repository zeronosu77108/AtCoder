#include <iostream>

using namespace std;


int main(void) {
    string str;
    int i,j;
    cin >> str;
    bool i_f, j_f;
    i_f = j_f = false;

    i = stoi( str.substr(0,2) );
    j = stoi( str.substr(2,2) );

    if ( 0<i && i<=12 ) {
        i_f = true;
    }
    if ( 0<j && j<=12 ) {
        j_f = true;
    }

    if (i_f && j_f) {
        cout << "AMBIGUOUS" << endl;
    } else if ( i_f ) {
        cout << "MMYY" << endl;
    } else if ( j_f ) {
        cout << "YYMM" << endl;
    } else {
        cout << "NA" << endl;
    }
}
