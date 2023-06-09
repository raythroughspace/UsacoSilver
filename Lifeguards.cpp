#include <bits/stdc++.h>
#define INF 1e8
using namespace std;
struct Cow{
    ssize_t l;
    ssize_t r;
};

bool operator<(const Cow& a, const Cow& b){
    return a.l < b.l;
}

int main() {
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);
    size_t N; cin >> N;
    vector<Cow> cows(N);
    for (size_t i=0; i<N; ++i){
        cin >> cows[i].l >> cows[i].r;
        cows[i].r--;
    }
    sort(cows.begin(), cows.end());
    size_t total_covered = 0;
    ssize_t right = 0;
    for (auto cow: cows){
        if (cow.r > right){
            if (right >= cow.l){
                total_covered += cow.r - right;
            }
            else{
                total_covered += cow.r - cow.l +1;
            }
            right = cow.r;
        }
    }
    size_t min_alone = INF;
    right = 0;
    for (size_t i=0; i<N; ++i){
        if (cows[i].r <= right){
            min_alone = 0;
        }
        size_t length = cows[i].r - cows[i].l + 1;
        ssize_t covered = max((ssize_t)0, right - cows[i].l + 1); // covered with cows i-1
        if (i+1 <N){
            covered += max((ssize_t)0, cows[i].r - cows[i+1].l + 1); // covered with cow i+1
            covered -= max((ssize_t)0, right - cows[i+1].l + 1); // intersection of covered region
        }
        min_alone = min(length-covered, min_alone);
        right = cows[i].r;
    }
    cout << total_covered - min_alone;

}