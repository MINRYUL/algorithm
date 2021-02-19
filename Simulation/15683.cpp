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
int n, m, arr[9][9], result = 80,
    dx[6] = {-1, 0, 1, 0, -1, 0},
    dy[6] = {0, -1, 0, 1, 0, -1};

vector<pair<int, int>> v;

void recu(int a){
    if(a == v.size()){
        int t = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) if(!arr[i][j]) t += 1;
        if(result > t) result = t;
        return;
    }
    int c = arr[v[a].first][v[a].second];
    int x = v[a].first, y = v[a].second;
    if(c == 1){
        for(int i = 0; i < 4; i++){
            int xx = x + dx[i], yy = y + dy[i];
            vector<pair<int, int>> ch;
            while(xx >= 0 && xx < n && yy >= 0 && yy < m){
                if(arr[xx][yy] == 6) break;
                if(!arr[xx][yy]){ arr[xx][yy] = -1; ch.push_back({xx, yy}); }
                xx += dx[i]; yy += dy[i];
            }
            recu(a + 1);
            for(pair<int, int> i : ch)
                arr[i.first][i.second] = 0;
        }
    }else if(c == 2){
        for(int i = 0; i < 2; i++){
            int xx = x + dx[i], yy = y + dy[i];
            vector<pair<int, int>> ch;
            while(xx >= 0 && xx < n && yy >= 0 && yy < m){
                if(arr[xx][yy] == 6) break;
                if(!arr[xx][yy]){ arr[xx][yy] = -1; ch.push_back({xx, yy}); }
                xx += dx[i]; yy += dy[i];
            }
            int xx2 = x + dx[i + 2], yy2 = y + dy[i + 2];
            while(xx2 >= 0 && xx2 < n && yy2 >= 0 && yy2 < m){
                if(arr[xx2][yy2] == 6) break;
                if(!arr[xx2][yy2]){ arr[xx2][yy2] = -1; ch.push_back({xx2, yy2}); }
                xx2 += dx[i + 2]; yy2 += dy[i + 2];
            }
            recu(a + 1);
            for(pair<int, int> i : ch)
                arr[i.first][i.second] = 0;
        }
    }else if(c == 3){
        for(int i = 0; i < 4; i++){
            int xx = x + dx[i], yy = y + dy[i];
            vector<pair<int, int>> ch;
            while(xx >= 0 && xx < n && yy >= 0 && yy < m){
                if(arr[xx][yy] == 6) break;
                if(!arr[xx][yy]){ arr[xx][yy] = -1; ch.push_back({xx, yy}); }
                xx += dx[i]; yy += dy[i];
            }
            int xx2 = x + dx[i + 1], yy2 = y + dy[i + 1];
            while(xx2 >= 0 && xx2 < n && yy2 >= 0 && yy2 < m){
                if(arr[xx2][yy2] == 6) break;
                if(!arr[xx2][yy2]){ arr[xx2][yy2] = -1; ch.push_back({xx2, yy2}); }
                xx2 += dx[i + 1]; yy2 += dy[i + 1];
            }
            recu(a + 1);
            for(pair<int, int> i : ch)
                arr[i.first][i.second] = 0;
        }
    }else if(c == 4){
        for(int i = 0; i < 4; i++){
            int xx = x + dx[i], yy = y + dy[i];
            vector<pair<int, int>> ch;
            while(xx >= 0 && xx < n && yy >= 0 && yy < m){
                if(arr[xx][yy] == 6) break;
                if(!arr[xx][yy]){ arr[xx][yy] = -1; ch.push_back({xx, yy}); }
                xx += dx[i]; yy += dy[i];
            }
            int xx2 = x + dx[i + 1], yy2 = y + dy[i + 1];
            while(xx2 >= 0 && xx2 < n && yy2 >= 0 && yy2 < m){
                if(arr[xx2][yy2] == 6) break;
                if(!arr[xx2][yy2]){ arr[xx2][yy2] = -1; ch.push_back({xx2, yy2}); }
                xx2 += dx[i + 1]; yy2 += dy[i + 1];
            }
            int xx3 = x + dx[i + 2], yy3 = y + dy[i + 2];
            while(xx3 >= 0 && xx3 < n && yy3 >= 0 && yy3 < m){
                if(arr[xx3][yy3] == 6) break;
                if(!arr[xx3][yy3]){ arr[xx3][yy3] = -1; ch.push_back({xx3, yy3}); }
                xx3 += dx[i + 2]; yy3 += dy[i + 2];
            }
            recu(a + 1);
            for(pair<int, int> i : ch)
                arr[i.first][i.second] = 0;
        }
    }else{
        vector<pair<int, int>> ch;
        for(int i = 0; i < 4; i++){
            int xx = x + dx[i], yy = y + dy[i];
            while(xx >= 0 && xx < n && yy >= 0 && yy < m){
                if(arr[xx][yy] == 6) break;
                if(!arr[xx][yy]){ arr[xx][yy] = -1; ch.push_back({xx, yy}); }
                xx += dx[i]; yy += dy[i];
            }
        }
        recu(a + 1);
        for(pair<int, int> i : ch)
            arr[i.first][i.second] = 0;
    }
}

int main(void) {
    ios :: sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
            if(arr[i][j] && arr[i][j] != 6) v.push_back({i, j});
        }
    }
    recu(0);
    cout << result << endl;
    return 0;
}
