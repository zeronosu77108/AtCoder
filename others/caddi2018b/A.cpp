#include <iostream>
#include <string>

using namespace std;

int count_char(string s,char x) {
    int count;
    for (auto c : s) {
        if ( c == x ) {
            count++;
        }
    }
    return count;
}

int main(){
    string s;
    cin >> s;
    cout << count_char(s,'2') << endl;
}
