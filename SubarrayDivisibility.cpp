#include <bits/stdc++.h>
using namespace std;

int main() {
    ssize_t n; cin >> n;
    vector<ssize_t> arr(n);
    for (size_t i=0; i<n; ++i){
        cin >> arr[i];
    }
    map<ssize_t, size_t> prefix;
    ssize_t sum = 0;
    prefix[0] = 1;
    size_t count = 0;
    for (auto e: arr){
        sum = (((sum + e) %n) + n)%n;
        count += prefix[sum];
        ++prefix[sum];
    }
    cout << count;
}
