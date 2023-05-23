#include <bits/stdc++.h>
#define MOD 2019
using namespace std;

int main() {
    string s; cin >> s;
    map<size_t, size_t> remainders;
    size_t power10 = 1;
    size_t suffix = 0;
    remainders[0] = 1;
    for (ssize_t i=s.size()-1; i>= 0; --i){
        suffix += power10*(s[i] - '0');
        suffix %= MOD;
        power10= (power10* 10)%MOD;
        ++remainders[suffix];
    }
    size_t count = 0;
    for (auto e: remainders){
        count += (e.second*(e.second-1))/2;
    }
    cout << count;

}
