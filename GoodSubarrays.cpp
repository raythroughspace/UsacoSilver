#include <bits/stdc++.h>
using namespace std;

int main() {
    size_t T; cin >> T;
    for (size_t i=0; i<T; ++i){
        size_t N; cin >> N;
        ssize_t prefix = 0;
        map<ssize_t, ssize_t> prefixes;
        prefixes[0] = 1;
        size_t count = 0;
        for (size_t j=0; j<N; ++j){
            char dig; cin >> dig;
            dig -= '1';
            prefix = prefix + dig;
            count += prefixes[prefix];
            ++prefixes[prefix];
        }
        cout << count << "\n";
    }
}
