#include <iostream>
#include <vector>

using namespace std;

int main() {
    int c[3][3];
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            cin >> c[i][j];
        }
    }

    int a[3],b[3];
    bool ans = false;
    for (int i=0; i<=100; i++) {
        int a[3],b[3];
        a[0] = i;
        for (int j=0; j<3; j++) b[j] = c[0][j] - a[0];
        a[1] = c[1][0] - b[0];
        a[2] = c[2][0] - b[0];

        bool f = true;
        for (int j=0; j<3; j++) {
            for (int k=0; k<3; k++) {
                if (c[j][k] != a[j] + b[k]) f = false;
            }
        }
        if (f) ans = true;
    }

    cout << (ans? "Yes" : "No") << endl;
}

/*
 * a1+b1 a1+b2 a1+b3
 * a2+b1 a2+b2 a2+b3
 * a3+b1 a3+b2 a3+b3
 */