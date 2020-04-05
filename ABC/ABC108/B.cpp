#include <iostream>

using namespace std;

int main() {
    int x1,x2,y1,y2;
    cin >> x1 >> y1 >> x2 >> y2;


    cout << x2 - (y2 - y1) << " ";
    cout << y2 + (x2 - x1) << " ";
    cout << x1 - (y2 - y1) << " ";
    cout << y1 + (x2 - x1) << endl;
}