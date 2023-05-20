#include <bits/stdc++.h>
#define INF 1e8
using namespace std;

int main() {
    freopen("maxcross.in", "r", stdin);
    freopen("maxcross.out", "w", stdout);
    size_t N,K,B; cin >> N >> K >> B;
    vector<size_t> lights(N, 0);
    for (size_t i=0; i<B; ++i){
        size_t idx; cin >> idx;
        lights[idx-1] = 1;
    }
    vector<size_t> prefix(N+1, 0);
    for (size_t i=1; i<N+1; ++i){
        prefix[i] = prefix[i-1] + lights[i-1];
    }
    size_t count = INF;
    for (size_t i=K; i<N+1; ++i){
        count = min(count, prefix[i] - prefix[i-K]);
    }
    cout << count;
}
