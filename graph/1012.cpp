//#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
#include <stack>
using namespace std;
int t, m, n, k, x, y, graden[51][51];
queue<pair<int, int>> q;

int xD[4] = {-1 , 0, 1, 0},
    yD[4] = {0, -1, 0, 1};

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while(t--){
        cin >> m >> n >> k; int result = 0;
        for(int i = 0; i < k; i++){
            cin >> x >> y; graden[y + 1][x + 1] = 1;
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(graden[i][j]){
                    q.push({i, j}); result++; graden[i][j] = 0;
                    while(!q.empty()){
                        int nextX = q.front().first, nextY = q.front().second;
                        q.pop();
                        for(int z = 0; z < 4; z++){
                            int xx = nextX + xD[z], yy = nextY + yD[z];
                            if(xx > 0 && yy > 0 && xx < 51 && yy < 51 && graden[xx][yy]){
                                q.push({xx, yy}); graden[xx][yy] = 0;
                            }
                        }
                    }
                }
            }
        }
        cout << result << endl;
    }
    return 0;
}
