#include <bits/stdc++.h>
#define INF 1e8
using namespace std;

int main() {
    freopen("stacking.in", "r", stdin);
    freopen("stacking.out", "w", stdout);
    size_t N,K; cin >> N >> K;
    map<size_t, size_t> As;
    map<size_t, size_t> Bs;
    for (size_t i=0; i<K; ++i){
        size_t a,b; cin >> a >> b;
        ++As[a-1]; ++Bs[b-1];
    }
    ++As[N]; ++Bs[N];
    vector<ssize_t> stacks(N);
    ssize_t count = 0;
    size_t idx = 0;
    for (auto e: As){
        for (size_t i = idx; i<e.first; ++i){
            stacks[i] += count;
        }
        count += e.second;
        idx = e.first;
    }
    count = 0;
    idx = 0;
    for (auto e: Bs){
        for (size_t i = idx; i<=min(e.first, N-1); ++i){
            stacks[i] -= count;
        }
        count += e.second;
        idx = e.first + 1;
    }
    sort(stacks.begin(), stacks.end());
    cout << stacks[(N-1)/2];
}
