#include <bits/stdc++.h>
#define INF 1e8
using namespace std;

int main() {
    //freopen("div7.in", "r", stdin);
    //freopen("div7.out", "w", stdout);
    size_t N; cin >> N;
    vector<size_t> IDs(N);
    for (size_t i=0; i<N; ++i){
        cin >> IDs[i];
    }
    vector<size_t> prefixMod7(N+1, 0);
    vector<size_t> first(7, INF);
    first[0] = 0;
    for (size_t i=1; i<N+1; ++i){
        prefixMod7[i] = (prefixMod7[i-1] + IDs[i]) % 7;
        first[prefixMod7[i]] = min(i, first[prefixMod7[i]]);
    }
    size_t largest = 0;
    for (size_t i=0; i<7; ++i){
        if (first[i] == INF){
            continue;
        }
        for (size_t j=0; j<N+1; ++j){
            if (prefixMod7[j] == i){
                largest = max(largest, j-first[i]);
            }
        }
    }
    cout << largest;
}
