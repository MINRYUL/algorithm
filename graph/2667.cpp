#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
    int dx[4] = {0, -1, 0, 1},
        dy[4] = {-1, 0, 1, 0};
    int graph[26][26] = {0, }, n, num = 0;
    bool visited[26][26] = {false, };
    vector<int> result;
    queue<pair<int, int>> q;
    
    scanf("%d", &n);
    for ( int i = 0; i < n; i++ ){
        for ( int j = 0; j < n; j++ ){
            scanf("%1d",&graph[i][j]);
        }
    }
    
    for ( int i = 0; i < n; i++ ){
        for ( int j = 0; j < n; j++ ){
            if (graph[i][j] && !visited[i][j]) {
                visited[i][j] = true;
                
                q.push({i, j});
                num += 1;
                int append = 0;
                while (!q.empty()) {
                    pair<int, int> temp = q.front();
                    q.pop();
                    
                    for ( int move = 0; move < 4; move++ ){
                        int xx = temp.first + dx[move];
                        int yy = temp.second+ dy[move];
                        
                        
                        if (xx < 0 || yy < 0 || xx >= n || yy >= n) continue;
                        if (visited[xx][yy] || !graph[xx][yy]) continue;
                        
                        append += 1;
                        visited[xx][yy] = true;
                        q.push({xx, yy});
                    }
                }
                result.push_back(append + 1);
            }
        }
    }
    
    sort(result.begin(), result.end());
    
    printf("%d\n", num);
    for (int i : result) {
        printf("%d\n", i);
    }

    return 0;
}
