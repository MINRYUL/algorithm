#include<bits/stdc++.h>
#define MAX 10001
using namespace std;
int v, e, x, y, num, ans, discovered[MAX];
vector<int> g[MAX];
bool isCut[MAX];

int dfs(int node, bool isRoot){
    discovered[node] = ++num;
    int ret = discovered[node];
    int child = 0;
    for(int i : g[node]){
        if(discovered[i]){  ret = min(ret, discovered[i]); continue; }
        int pev = dfs(i, false); child++;
        if(!isRoot && pev >= discovered[node]) isCut[node] = true;
        ret = min(ret, pev);
    }
    if(isRoot) isCut[node] = (child >= 2);
    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> v >> e;
    while(e--){ cin >> x >> y; g[x].push_back(y); g[y].push_back(x); }
    for(int i = 1; i <= v; i++) if(!discovered[i]) dfs(i, true);
    for(int i = 1; i <= v; i++) if(isCut[i]) ++ans;
    cout << ans << endl;
    for(int i = 1; i <= v; i++) if(isCut[i]) cout << i << ' ';
    
    return 0;
}
