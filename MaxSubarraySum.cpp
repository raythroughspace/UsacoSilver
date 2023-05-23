#include <bits/stdc++.h>
#define INF 1e10
using namespace std;

int main() {
    size_t n; cin >> n;
    ssize_t prefix = 0;
    ssize_t min_p = 0;
    ssize_t max_sum = -INF;
    for (size_t i=1; i<=n; ++i){
        ssize_t x; cin >> x;
        prefix += x;
        max_sum = max(prefix- min_p, max_sum);
        min_p = min(prefix, min_p);
    }
    cout << max_sum;


}
