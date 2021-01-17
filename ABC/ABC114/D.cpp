//
// Created by zeronosu77108 on Jan 17, 2021.
//
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void factorize(int n, unordered_map<int,long>& mp) {
    while(n%2==0) n/=2, mp[2]++;
    for (int i=3; i<=n; i+=2) {
        while (n%i==0) n/=i, mp[i]++;
    }
    if (n!=1) mp[n]++;
}



int main() {
    int n;
    cin >> n;

    unordered_map<int, long> mp;
    for (int i=2; i<=n; i++) factorize(i, mp);

    // 5 * 5 * 3
    // 75, 25*3, 15*5, 5*5*3
    long ans = count_if(mp.begin(), mp.end(), [](const pair<int,long> p){ return p.second >= 74;});


    { // 25*3
        long t1 = count_if(mp.begin(), mp.end(), [](const pair<int,long> p){ return p.second >= 24; });
        long t2 = count_if(mp.begin(), mp.end(), [](const pair<int,long> p){ return p.second >= 2; });
        ans += t1 * (t2 - 1);
    }


    { // 5 * 15
        long t1 = count_if(mp.begin(), mp.end(), [](const pair<int,long> p){ return p.second >= 14; });
        long t2 = count_if(mp.begin(), mp.end(), [](const pair<int,long> p){ return p.second >= 4; });
        ans += t1 * (t2 - 1);
    }


    { // 5 * 5 * 3
        long t1 = count_if(mp.begin(), mp.end(), [](const pair<int,long> p){ return p.second >= 4; });
        long t2 = count_if(mp.begin(), mp.end(), [](const pair<int,long> p){ return p.second >= 2; });
        ans += t1 * (t1 - 1) / 2 * (t2 - 2);
    }

    cout << ans << endl;
}