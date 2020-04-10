#include <iostream>
#include <map>

using namespace std;

int main() {
    map<char,char> ans;
    ans['A'] = 'T';
    ans['T'] = 'A';
    ans['G'] = 'C';
    ans['C'] = 'G';

    char b;
    cin >> b;
    cout << ans[b] << endl;
}
