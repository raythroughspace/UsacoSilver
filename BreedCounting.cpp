#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);
    size_t N, Q; cin >> N >> Q;
    vector<size_t> breeds(N);
    for (size_t i=0; i<N; ++i){
        cin >> breeds[i];
    }
    vector<size_t> prefixH(N+1,0);
    vector<size_t> prefixG(N+1,0);
    vector<size_t> prefixJ(N+1,0);
    for (size_t i=1; i<N+1; ++i){
        prefixH[i] = prefixH[i-1];
        prefixG[i] = prefixG[i-1];
        prefixJ[i] = prefixJ[i-1];
        if (breeds[i-1] == 1){
            ++prefixH[i];
        }
        else if (breeds[i-1] == 2){
            ++prefixG[i];
        }
        else{
            ++prefixJ[i];
        }
    }
    for (size_t i=0; i<Q; ++i){
        size_t a,b; cin >> a >> b;
        cout << prefixH[b] - prefixH[a-1] << " ";
        cout << prefixG[b] - prefixG[a-1] << " ";
        cout << prefixJ[b] - prefixJ[a-1] << "\n";
    }
}
