#include <bits/stdc++.h>
using namespace std;

int main() {
    size_t N; cin >> N;
    vector<size_t> board(N);
    for (size_t i=0; i<N; ++i){
        cin >> board[i];
    }
    vector<size_t> prefix(N);
    prefix[0] = board[0];
    for (size_t i=1; i<N; ++i){
        prefix[i] = gcd(prefix[i-1], board[i]);
    }
    vector<size_t> suffix(N);
    suffix[N-1] = board[N-1];
    for (ssize_t i=N-2; i>=0; --i){
        suffix[i] = gcd(suffix[i+1], board[i]);
    }
    size_t largest = max(prefix[N-2], suffix[1]);
    for(size_t i=1; i<N-1; ++i){
        largest = max(gcd(prefix[i-1], suffix[i+1]), largest);
    }
    cout << largest;

}
