#include <bits/stdc++.h>
#define INF 1e8
using namespace std;

int main() {
    freopen("rental.in", "r", stdin);
    freopen("rental.out", "w", stdout);
    size_t N,M,R; cin >> N >> M >> R;
    vector<size_t> milk(N);
    for (size_t i=0; i<N; ++i){
        cin >> milk[i];
    }
    vector<pair<size_t, size_t>> stores(M);
    for (size_t i=0; i<M; ++i){
        cin >> stores[i].second >> stores[i].first;
    }
    vector<size_t> rent(R);
    for (size_t i=0; i<R; ++i){
        cin >> rent[i];
    }
    sort(milk.rbegin(), milk.rend());
    sort(stores.rbegin(), stores.rend());
    sort(rent.rbegin(), rent.rend());

    size_t storesIdx = 0; size_t rentIdx = 0;
    ssize_t left = 0; ssize_t right = N-1;
    size_t profit = 0;
    while (left <= right){
        size_t milkPrice = 0;
        ssize_t amt = milk[left];
        while (storesIdx < M){
            if (amt ==0){
                break;
            }
            if (amt < stores[storesIdx].second){
                stores[storesIdx].second -= amt;
                milkPrice += amt*stores[storesIdx].first;
                amt = 0;
            }
            else{
                milkPrice += stores[storesIdx].first * stores[storesIdx].second;
                amt -= stores[storesIdx].second;
                stores[storesIdx].second = 0;
                ++storesIdx;
            }
        }

        if (milkPrice >= rent[rentIdx]){
            profit += milkPrice;
            ++left;
        }
        else{
            while (milkPrice < rent[rentIdx]){
                if (left > right){
                    break;
                }
                profit += rent[rentIdx];
                --right;
                ++rentIdx;
            }
            if (left > right){
                break;
            }
            profit += milkPrice;
            ++left;
        }

    }
    cout << profit;
}