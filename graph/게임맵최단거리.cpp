#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <queue>
#include <string>
#include <stack>
#include <map>
#include <queue>

using namespace std;

struct pos{
    int x, y;
};

int solution(vector<vector<int> > maps)
{
    int dx[4] = {-1, 0, 1, 0},
        dy[4] = {0, -1, 0, 1};
    bool visited[101][101] = {false, };
    if(maps.size() == 1 && maps[0].size() == 1) return 1;
    
    queue<pair<pos, int>> q;
    q.push({{0, 0}, 1}); visited[0][0] = true;
    while(!q.empty()){
        pos p = q.front().first;
        int t = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int xx = dx[i] + p.x, yy = dy[i] + p.y;
            if(xx < 0 || yy < 0 || xx >= maps.size() || yy >= maps[0].size() || visited[xx][yy] || !maps[xx][yy])
                continue;
            visited[xx][yy] = true;
            if(xx == maps.size() - 1 && yy == maps[0].size() - 1)
                return t + 1;
            q.push({{xx, yy}, t + 1});
        }
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cout << solution({{1, 0, 1, 1, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 1, 1}, {1, 1, 1, 0, 1}, {0, 0, 0, 0, 1}}) << endl;
    return 0;
}


