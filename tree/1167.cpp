//#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
#define MAX 100001
using namespace std;
vector<pair<int, int>> t[MAX];
bool check[MAX];
long long depth[MAX];
int m;

void dfs(int x){
    check[x] = true;
    for(int i = 0; i < t[x].size(); i++){
        if(!check[t[x][i].first]){
            check[t[x][i].first] = true;
            depth[t[x][i].first] = t[x][i].second + depth[x];
            if(depth[t[x][i].first] > depth[m]) m = t[x][i].first;
            dfs(t[x][i].first);
        }
    }
}

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    while(n--){
        int x, y, z;
        cin >> x;
        while(true){
            cin >> y;
            if(y == -1) break;
            cin >> z;
            t[x].push_back(make_pair(y, z));
            t[y].push_back(make_pair(x, z));
        }
    }
    dfs(1);
    memset(depth, 0, sizeof(depth));
    memset(check, false, sizeof(check));
    
    dfs(m);
    cout << depth[m] << endl;
    return 0;
}
