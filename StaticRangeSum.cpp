#include <bits/stdc++.h>
using namespace std;

int main() {
    size_t N,Q; cin >> N >> Q;
    vector<size_t> A(N);
    vector<size_t> pref(N+1, 0);
    for (size_t i=0; i<N; ++i){
        cin >> A[i];
    }
    for(size_t i=1; i<=N; ++i){
        pref[i] = pref[i-1] + A[i-1];
    }
    for (size_t i=0; i<Q; ++i){
        size_t l,r; cin >> l >> r;
        cout << pref[r] - pref[l] << "\n";
    }
}
