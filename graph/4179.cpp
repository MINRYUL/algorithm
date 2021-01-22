//#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm> //sort ..
#include <queue>
#include <string>
#include <map>
#include <stack>
#include <cstring> //memset
#include <utility> //pair
#define MAX 1001
using namespace std;
int r, c, check = 1,
    dx[4] = {-1, 0, 1, 0},
    dy[4] = {0, -1, 0, 1};
vector<pair<int, int>> start, fire, a, b;
char g[MAX][MAX];
struct Pos{ int x, y; };
bool visited[MAX][MAX];

bool find(){
    vector<pair<int, int>> v;
    for(pair<int, int> i : a){
        g[i.first][i.second] = 'J'; visited[i.first][i.second] = true;
        if(!i.first || !i.second || i.first == (r - 1) || i.second == (c - 1))
            v.push_back({i.first, i.second});
    }
    for(pair<int, int> i : b){ g[i.first][i.second] = 'F'; visited[i.first][i.second] = true; }
    for(pair<int, int> i : v){
        if(g[i.first][i.second] == 'J'){
            a.clear(); b.clear(); check++;
            return true;
        }
    }
    a.clear(); b.clear(); check++;
    return false;
}

int main(void) {
    cin >> r >> c;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> g[i][j];
            if(g[i][j] == 'J'){ start.push_back({i, j}); a.push_back({i, j}); }
            else if(g[i][j] == 'F') fire.push_back({i, j});
        }
    }
    if(find()){ cout << 1 << endl; return 0; }
    queue<pair<Pos, int>> q;
    for(pair<int, int> i : start){
        Pos s = { i.first, i.second }; q.push({s, 0});
    }
    for(pair<int, int> i : fire){
        Pos f = { i.first, i.second }; q.push({f, 0});
    }
    
    while(!q.empty()){
        int x = q.front().first.x, y = q.front().first.y, t = q.front().second; q.pop();
        for(int i = 0; i < 4; i++){
            int xx = x + dx[i], yy = y + dy[i];
            if(check == t){
                if(find()){ cout << t + 1 << endl; return 0; }
            }
            if(xx >= 0 && yy >= 0 && xx < r && yy < c ){
                Pos p = {xx, yy};
                if(g[xx][yy] == '.' && !visited[xx][yy]){
                    q.push({p, t + 1}); visited[xx][yy] = true;
                    if(g[x][y] == 'J'){ a.push_back({xx, yy}); g[xx][yy] = 'J'; }
                    else if(g[x][y] == 'F'){ b.push_back({xx, yy}); g[xx][yy] = 'F'; }
                }else if(g[xx][yy] == 'J' && g[x][y] == 'F'){
                    q.push({p, t + 1}); b.push_back({xx, yy}); g[xx][yy] = 'F';
                }
            }
        }
    }
    
    if(find()) cout << check + 1 << endl;
    else cout << "IMPOSSIBLE" << endl;
    return 0;
}
