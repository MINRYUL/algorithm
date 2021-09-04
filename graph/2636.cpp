#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
    int dx[4] = {0, -1, 0, 1},
        dy[4] = {-1, 0, 1, 0};
    int n, m, graph[101][101], time = 0;
    cin >> n >> m;
    
    for ( int i = 0; i < n; i++ )
        for ( int j = 0; j < m; j++ )
            cin >> graph[i][j];
    
    while (1) {
        queue<pair<int, int>> q;
        vector<pair<int, int>> cheeze;
        bool visited[101][101] = {false, };
        q.push({0, 0});
        visited[0][0] = true;
        
        while(!q.empty()) {
            pair<int, int> index = q.front();
            q.pop();
            for ( int i = 0; i < 4; i++ ) {
                int xx = index.first + dx[i];
                int yy = index.second + dy[i];
                
                if (xx < 0 || yy < 0 || xx >= n || yy >= m) continue;
                if (visited[xx][yy]) continue;
                
                if (graph[xx][yy]) {
                    cheeze.push_back({xx, yy});
                    visited[xx][yy] = true;
                    continue;
                }
                visited[xx][yy] = true;
                q.push({xx, yy});
            }
        }
        
        int air = 0;
        for ( int i = 0; i < n; i++ )
            for ( int j = 0; j < m; j++ )
                if ( !graph[i][j] ) air += 1;
        
        if (cheeze.size() + air == n * m) {
            cout << time + 1 << "\n" << cheeze.size() << endl;
            break;
        }
        
        for (pair<int, int> i : cheeze)
            graph[i.first][i.second] = 0;

        time += 1;
    }

    return 0;
}
