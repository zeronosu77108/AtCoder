#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    for (int i=0; i<n; i+=2)
        putchar(s[i]);
    cout << endl;
}