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
#define MAX 10
using namespace std;
int n, m, graph[MAX][MAX], r, s;
int dx[4] = {-1, 0, 1, 0},
    dy[4] = {0, -1, 0, 1};
bool visited[65];
struct Pos{
    int x, y;
};
vector<Pos> v, v2, v3;
 
void dfs(int I, int c) //조합을 dfs로 구현
{
    if (c == 3){
        vector<Pos> check;
        for (int i = 0; i < s; i++)
            if (visited[i] == true) check.push_back(v[i]);
            
        queue<pair<int, int>> q; bool infection[MAX][MAX] = {false, };
        for(Pos i : check){ graph[i.x][i.y] = 1; infection[i.x][i.y] = true; }
        for(Pos i : v2){
            q.push({i.x, i.y}); infection[i.x][i.y] = true;
        }
        for(Pos i : v3) infection[i.x][i.y] = true;
        
        while(!q.empty()){
            int x = q.front().first, y = q.front().second; q.pop();
            for(int i = 0; i < 4; i++){
                int xx = x + dx[i], yy = y + dy[i];
                if(xx >= 0 && yy >= 0 && xx < n && yy < m && !graph[xx][yy] && !infection[xx][yy]){
                    q.push({xx, yy}); infection[xx][yy] = true;
                }
            }
        }
        int temp = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(!infection[i][j]) temp += 1;
            
        if(r < temp) r = temp;
        
        for(Pos i : check) graph[i.x][i.y] = 0;
        return;
    }
    for (int i = I; i < s; i++){
        if (visited[i] == true) continue;
        visited[i] = true;

        dfs(i, c + 1);
        visited[i] = false;
    }
}
 

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> graph[i][j];
            Pos p = {i, j};
            if(graph[i][j] == 2)    v2.push_back(p);
            else if(graph[i][j] == 0) v.push_back(p);
            else v3.push_back(p);
        }
    }

    s = v.size(); dfs(0, 0);
    cout << r << endl;
    return 0;
}
