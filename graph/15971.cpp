//#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#define MAX 100001
using namespace std;
vector<pair<int, int>> t[MAX];
bool check[MAX];
int r1, r2, n, x, y, w, weight[MAX], p[MAX];

void dfs(int x1){
    check[x1] = true;
    for(int i = 0; i < t[x1].size(); i++){
        if(!check[t[x1][i].first]){
            p[t[x1][i].first] = x1;
            weight[t[x1][i].first] = t[x1][i].second;
            if(t[x1][i].first == r2) return;
            dfs(t[x1][i].first);
        }
    }
}
void sumWeight(int x1){
    if(x1 == r1) return;
    if(x < weight[x1])   x = weight[x1];
    w += weight[x1];
    sumWeight(p[x1]);
}

int main() {
    cin >> n >> r1 >> r2; --n;
    while(n--){
        cin >> x >> y >> w;
        t[x].push_back(make_pair(y, w));
        t[y].push_back(make_pair(x, w));
    }
    w = 0; x = 0; dfs(r1);
    sumWeight(r2);
    
    cout << w - x << endl;
    return 0;
}
