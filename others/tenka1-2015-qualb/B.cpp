#include <iostream>
#include <string>

using namespace std;

void endof(const string& s, int& i, const int& n) {
    while(i < n) {
        if (s[i] == '}') return;
        if (s[i] == '{') endof(s,++i,n);
        i++;
    }
}


int main() {
    string s;
    cin >> s;
    int n = s.size();

    if (n == 2 && s[0] == '{' && s[1] == '}') {
        cout << "dict" << endl;
        return 0;
    }

    auto num = [](const char& c) { return '0'<=c && c<='9'; };
    if (all_of(s.begin(), s.end(), num)) {
        cout << "integer" << endl;
        return 0;
    }

    for (int i=1; i<n; i++) {
        if (s[i] == ':') {
            cout << "dict" << endl;
            return 0;
        }

        if (s[i] == ',') {
            cout << "set" << endl;
            return 0;
        }

        if (s[i] == '{') {
            endof(s, ++i, n);
        }
    }

    cout << "set" << endl;
}
