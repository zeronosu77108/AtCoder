#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    cout << 700 + 100*count(s.begin(),s.end(),'o') << endl;
}