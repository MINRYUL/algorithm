#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;
vector<int> graph[2001];
int n, m;
bool result = false;

void dfs(int index, bool *visited, int depth) {
    if ( 5 <= depth ) {
        result = true;
        return;
    }
    visited[index] = true;
    for ( int i :  graph[index]) {
        if (visited[i]) continue;
        dfs(i, visited, depth + 1);
        visited[i] = false;
    }
}

int main(){
    cin >> n >> m;
    
    for ( int i = 0; i < m; i++ ) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    for (int i = 0; i < n; i++) {
        bool visited[2001] = {false, };
        dfs(i, visited, 1);
        if (result){
            cout << 1;
            return 0;
        }
    }
    cout << 0;
    
    return 0;
}
