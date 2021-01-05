#include<bits/stdc++.h>
using namespace std;
int N, R, x, y;
pair<int, int> P[1001], D[1001];

int dis(int i, int j){
    return pow(P[i].first - P[j].first, 2) + pow(P[i].second - P[j].second, 2);
}

int main(void) {
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> x >> y; P[i] = {x, y};
    }
    int min = INT_MAX;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i == j) continue;
            int d = dis(i, j);
            if(D[i].first < d) D[i] = {d, j};
        }
        if(min > D[i].first){
            min = D[i].first; R = i;
        }
    }
    cout << P[R].first << ' ' << P[R].second;
    return 0;
}
