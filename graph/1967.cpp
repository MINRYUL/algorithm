#include<bits/stdc++.h>
#define MAX 10001
using namespace std;
int n, x, y, z, d, f;
vector<pair<int, int>> t[MAX];
bool visited[MAX];

void dfs(int s, int sum){
    visited[s] = true;
    if(sum > d){ d = sum; f = s; }
    for(pair<int, int> i : t[s])
        if(!visited[i.first]) dfs(i.first, i.second + sum);
}

int main(void) {
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x >> y >> z;
        t[x].push_back({y, z}); t[y].push_back({x, z});
    }
    dfs(1, 0); d = 0;
    memset(visited, false, sizeof(visited));
    dfs(f, 0); cout << d << endl;
    return 0;
}
