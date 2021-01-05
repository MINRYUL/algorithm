#include<bits/stdc++.h>
#define MAX 100001
using namespace std;
int v, e, x, y, num, discovered[MAX];
vector<int> g[MAX];
vector<pair<int, int>> result;

int dfs(int node, int parent){
    discovered[node] = ++num;
    int ret = discovered[node];
    for(int i : g[node]){
        if(parent == i) continue;
        if(discovered[i]){
            ret = min(ret, discovered[i]);
            continue;
        }
        int pev = dfs(i, node);
        if(pev > discovered[node]){
            if(node < i) result.push_back({node, i});
            else result.push_back({i, node});
        }
        ret = min(ret, pev);
    }
    return ret;
}

int main() {
    scanf("%d%d", &v, &e);
    for(int i =1 ; i<= e; i++){
        scanf("%d%d", &x, &y); g[x].push_back(y); g[y].push_back(x);
    }
    dfs(1, 0);
    cout << result.size() << endl; sort(result.begin(), result.end());
    for(pair<int, int> i : result) printf("%d %d \n", i.first, i.second);
    return 0;
}
