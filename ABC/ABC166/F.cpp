//
// Created by zeronosu77108 on Dec 27, 2020.
//
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector a(3, 0);
    for (int i=0; i<3; i++) cin>>a[i];

    vector<string> s(n);
    for (int i=0; i<n; i++) cin >> s[i];

    bool f = true;
    vector<char> ans;
    for (int i=0; i<n; i++) {
        int front = s[i].front() - 'A';
        int back = s[i].back() - 'A';

        if (a[front] < a[back]) swap(front, back);

        if (a[back] == 0) {
            if (a[front] == 0) {
                f = false;
                break;
            }
            ans.push_back(back + 'A');
            a[front]--;
            a[back]++;
        } else if (i+1<n && a[front] == 1) {
            if (front == (s[i+1].front()-'A') || front == s[i+1].back()-'A') {
                ans.push_back(front + 'A');
                a[front]++;
                a[back]--;
            } else {
                ans.push_back(back + 'A');
                a[front]--;
                a[back]++;
            }
        } else {
            ans.push_back(back + 'A');
            a[front]--;
            a[back]++;
        }
    }

    if (f) {
        cout << "Yes" << endl;
        for (const auto& a : ans) cout<<a<<endl;
    } else {
        cout << "No" << endl;
    }
}