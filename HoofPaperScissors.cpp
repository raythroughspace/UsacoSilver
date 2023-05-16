#include <bits/stdc++.h>
#define NMOVES 3
using namespace std;

int main() {
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    size_t N; cin >> N;
    vector<char> gestures(N);
    for (size_t i=0; i<N; ++i){
        cin >> gestures[i];
    }
    vector<vector<size_t>> prefixes(NMOVES, vector<size_t>(N+1, 0)); //0 = H, 1 = P, 2 = S
    for (size_t i=1; i<N+1; ++i){
        for (size_t j=0; j<NMOVES; ++j){
            prefixes[j][i] = prefixes[j][i-1];
        }
        if (gestures[i-1] == 'H'){
            ++prefixes[1][i];
        }
        else if (gestures[i-1] == 'P'){
            ++prefixes[2][i];
        }
        else{
            ++prefixes[0][i];
        }
    }
    size_t max_score = 0;
    for (size_t i=0; i<NMOVES; ++i){
        for (size_t j=0; j<NMOVES; ++j){
            for (size_t x=0; x<N+1; ++x){
                size_t score = prefixes[i][x] + prefixes[j][N] - prefixes[j][x];
                max_score = max(score, max_score);
            }
        }
    }
    cout << max_score;
}
