#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <queue>
#include <string>
#include <stack>
#include <map>

using namespace std;



vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    bool visited[101][101] = {false, };
    int dx[4] = {-1, 0, 1, 0},
        dy[4] = {0, -1, 0, 1};
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(picture[i][j] && !visited[i][j]){
                queue<pair<int, int>> q; q.push({i, j}); int color = picture[i][j];
                visited[i][j] = true; number_of_area++; int temp = 1;
                while(!q.empty()){
                    int x = q.front().first, y = q.front().second; q.pop();
                    for(int k = 0; k < 4; k++){
                        int xx = x + dx[k], yy = y + dy[k];
                        if(xx < 0 || yy < 0 || xx >= m || yy >= n) continue;
                        if(color == picture[xx][yy] && !visited[xx][yy]){
                            q.push({xx, yy}); visited[xx][yy] = true; temp++;
                        }
                    }
                }
                max_size_of_one_area = max(max_size_of_one_area, temp);
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solution(6, 4, {{1, 1, 1, 0}, {1, 2, 2, 0}, {1, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 3}, {0, 0, 0, 3}});
    return 0;
}

