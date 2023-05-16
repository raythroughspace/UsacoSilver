#include <bits/stdc++.h>
using namespace std;

int main() {
    ssize_t n,x; cin >> n >> x;
    vector<ssize_t> arr(n);
    for (size_t i=0; i<n; ++i){
        cin >> arr[i];
    }
    map<ssize_t, size_t> prefix;
    ssize_t sum = 0;
    prefix[0] = 1;
    size_t count = 0;
    for (auto e: arr){
        sum += e;
        count += prefix[sum-x];
        ++prefix[sum];
    }
    cout << count;
}
