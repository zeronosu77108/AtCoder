//
// Created by zeronosu77108 on Dec 17, 2020.
//
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, k, c;
    string s;
    cin >> n >> k >> c >> s;

    vector<bool> w(n, true);

    vector<int> front;
    {
        int pre = INT_MIN;
        int i = 0;
        while (front.size() < k) {
            if (s[i]!='x' && pre+c < i) {
                front.push_back(i);
                pre = i;
            }
            i++;
        }
    }

    vector<int> back;
    {
        int pre = INT_MAX;
        int i = n-1;
        while (back.size() < k) {
            if (s[i]!='x' && i+c < pre) {
                back.push_back(i);
                pre = i;
            }
            i--;
        }
        reverse(back.begin(), back.end());
    }

    for (int i=0; i<k; i++) {
        if (front[i] == back[i]) {
            cout << front[i]+1 << endl;
        }
    }
}