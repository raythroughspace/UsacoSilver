#include <bits/stdc++.h>
using namespace std;

int main() {
    size_t n; cin >> n;
    size_t N = 2*n;
    vector<pair<size_t, size_t>> customers;
    vector<size_t> distinct;
    for (size_t i=0; i<n; ++i){
        size_t a,b; cin >> a >> b;
        customers.push_back({a,b});
        distinct.push_back(a);
        distinct.push_back(b);
    }
    sort(distinct.begin(), distinct.end());
    map<size_t, size_t> compress;
    for (size_t i=0; i<N; ++i){
        compress[distinct[i]] = i;
    }
    for (size_t i=0; i<n; ++i){
        customers[i] = {compress[customers[i].first], compress[customers[i].second]};
    }
    vector<size_t> times(N+1,0);
    for (size_t i=0; i<n; ++i){
        times[customers[i].first]++;
        times[customers[i].second]--;
    }
    vector<size_t> count(N+1, 0);
    for (size_t i=0; i<N; ++i){
        if (i>0){
            count[i] = count[i-1];
        }
        count[i] += times[i];
    }
    size_t maximum = 0;
    for (auto e: count){
        maximum = max(e, maximum);
    }
    cout << maximum;

}
