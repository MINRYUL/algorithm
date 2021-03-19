//#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm> //sort ..
#include <queue>
#include <string>
#include <map>
#include <stack>
#include <cmath> //pow, sqrt
#include <cstring> //memset
#include <utility> //pair
using namespace std;
int n, r, o, e, graph[11][11];
int dx[4] = {1, -1, -1, 1},
    dy[4] = {1, 1, -1, -1};
vector<pair<int, int>> oddQueen;
vector<pair<int, int>> evenQueen;

bool visitedCheck(int x, int y){
    for(int i = 0; i < 4; i++){
        int xx = x + dx[i], yy = y + dy[i];
        for(int j = 1; j < n; j++){
            if(xx < 0 || yy < 0 || xx >= n || yy >= n) break;
            if(graph[xx][yy] == 2) return false;
            xx += dx[i]; yy += dy[i];
        }
    }
    return true;
}

void dfs(int I, vector<pair<int, int>>& queen, bool oe, int num){
    for(int i = I; i < queen.size(); i++){
        int xx = queen[i].first, yy = queen[i].second;
        if(graph[xx][yy] == 1 && visitedCheck(xx, yy)){
            graph[xx][yy] = 2;
            dfs(i + 1, queen, oe, num + 1);
            graph[xx][yy] = 1;
        }
    }
    if(!oe && num > o) o = num;
    else if(oe && num > e) e = num;
}

int main(void) {
    ios :: sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> graph[i][j];
            if(graph[i][j]){
                if(!((i + j) % 2)) oddQueen.push_back({i, j});
                else evenQueen.push_back({i, j});
            }
        }
    }
    dfs(0, oddQueen, false, 0); dfs(0, evenQueen, true, 0);
    r = o + e; cout << r << endl;
    return 0;
}
