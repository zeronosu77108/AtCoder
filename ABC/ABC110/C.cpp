#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>

using namespace std;

int main() {
  string s,t;
  cin >> s; cin >> t;
  bool ans = true;
  map<char, char> repl1;
  map<char, char> repl2;
  int n = s.size();

  for (int i=0; i<26; i++) {
    repl1['a'+i] = '-';
    repl2['a'+i] = '-';
  }

  for (int i=0; i<n; i++) {
    // if (s[i] == t[i]) continue;

    if (repl1[s[i]]=='-') {
      repl1[s[i]] = t[i];
    }

    if(repl2[t[i]]=='-') {
      repl2[t[i]] = s[i];
    }

    if ((repl1[s[i]]!='-' && repl1[s[i]]!=t[i])
        || (repl2[t[i]]!='-' && repl2[t[i]]!=s[i])) {
      ans = false;
      break;
    }
  }

  cout << (ans? "Yes" : "No") << endl;
}

/*
abc
aaa

b → c
c → a

b ← a
c ← a
*/