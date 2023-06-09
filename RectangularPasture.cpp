#include <bits/stdc++.h>
using namespace std;
bool cmp(const pair<size_t, size_t>& a, const pair<size_t,size_t>& b){
    return a.second < b.second;
}
void compress(vector<pair<size_t, size_t>>& points){
    size_t N = points.size();
    sort(points.begin(), points.end());
    for (size_t i=0; i<N; ++i){
        points[i].first = i+1;
    }
    sort(points.begin(), points.end(), cmp);
    for(size_t i=0; i<N; ++i){
        points[i].second = i+1;
    }
}
int main() {
    size_t N; cin >> N;
    vector<pair<size_t,size_t>> points;
    for (size_t i=0; i<N; ++i){
        size_t x,y; cin >> x >> y;
        points.push_back({x,y});
    }
    compress(points);
    vector<vector<size_t>> grid(N+1, vector<size_t>(N+1, 0));
    for (auto pt: points){
        grid[pt.first][pt.second] = 1;
    }
    vector<vector<size_t>> prefix(N+1, vector<size_t>(N+1, 0));
    for (size_t i=1; i<=N; ++i){
        for (size_t j=1; j<=N; ++j){
            prefix[i][j] = prefix[i][j-1] + prefix[i-1][j] - prefix[i-1][j-1] + grid[i][j];
        }
    }
    size_t subsets = N+1;
    sort(points.begin(), points.end());
    for (size_t i=0; i<N; ++i){
        pair<size_t, size_t> pt1 = points[i];
        for (size_t j=i+1; j<N; ++j){
            pair<size_t, size_t> pt2 = points[j];
            size_t a,b,A,B;
            a = min(pt1.first, pt2.first);
            A = max(pt1.first, pt2.first);
            b = min(pt1.second, pt2.second);
            B = max(pt1.second, pt2.second);
            size_t above = prefix[A][N] - prefix[A][B-1] - prefix[a-1][N] + prefix[a-1][B-1];
            size_t below = prefix[A][b] - prefix[a-1][b] - prefix[A][0] + prefix[a-1][0];
            subsets += above*below;
        }
    }
    cout << subsets;

}
