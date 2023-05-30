#include <bits/stdc++.h>
using namespace std;

int main() {
    size_t n,q; cin >> n >> q;
    vector<vector<size_t>> rowTrees(n+1, vector<size_t>(n+1, 0));
    for (size_t i=1; i<=n; ++i){
        size_t rowSum = 0;
        for (size_t j=1; j<=n; ++j){
            char c; cin >> c;
            if (c == '*'){
                ++rowSum;
            }
            rowTrees[i][j] = rowSum;
        }
    }
    vector<vector<size_t>> prefix(n+1, vector<size_t>(n+1, 0));
    for (size_t i=1; i<=n; ++i){
        for (size_t j=1; j<=n; ++j){
            prefix[i][j] = prefix[i-1][j] + rowTrees[i][j];
        }
    }
    for(size_t i=0; i<q; ++i){
        size_t a,b,c,d; cin >> a >> b >> c >> d;
        ssize_t nTrees = prefix[c][d] + prefix[a-1][b-1] - prefix[c][b-1] - prefix[a-1][d];
        cout << nTrees << "\n";
    }
}
