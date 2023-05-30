#include <bits/stdc++.h>
using namespace std;
size_t find_reach(const vector<vector<ssize_t>>& prefixes, ssize_t i, ssize_t j, ssize_t K){
    ssize_t nreach = 0;
    ssize_t k = K;
    ssize_t N = prefixes.size();
    for (ssize_t x = 0; x <=K; ++x){
        size_t C = min(j+k+1, N);
        size_t c = max((ssize_t)0, j-k);
        if (i+x >=0 && i+x < N){
            nreach = nreach + prefixes[x+i][C] - prefixes[x+i][c];
        }
        if (i-x >=0 && i-x < N && x != 0){
            nreach = nreach + prefixes[i-x][C] - prefixes[i-x][c];
        }
        --k;
    }
    return nreach;
}
int main() {
    freopen("lazy.in", "r", stdin);
    freopen("lazy.out", "w", stdout);
    size_t N,K; cin >> N >> K;
    vector<vector<ssize_t>> prefixes(N, vector<ssize_t>(N+1, 0));
    for (size_t i=0; i<N; ++i){
        size_t rowSum = 0;
        for (size_t j=1; j<=N; ++j){
            size_t x; cin >> x;
            rowSum += x;
            prefixes[i][j] = rowSum;
        }
    }
    size_t max_reach = 0;
    for(size_t i=0; i<N; ++i){
        for (size_t j=0; j<N; ++j){
            max_reach = max(find_reach(prefixes, i, j, K), max_reach);
        }
    }
    cout << max_reach;
}
