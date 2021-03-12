#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
int n, m, r, g[501][501], dp[501][501];
int dx[4] = {-1, 0, 1, 0},
    dy[4] = {0, 1, 0, -1};

void dfs(int x, int y){
    if(dp[x][y] == -1) dp[x][y] = 0;
    for(int i = 0; i < 4; i++){
        int xx = x + dx[i], yy = y + dy[i];
        if(xx >= 0 && yy >= 0 && xx < n && yy < m){
            if(g[xx][yy] >= g[x][y] || !dp[xx][yy]) continue;
            if(dp[xx][yy] > 0){
                dp[x][y] += dp[xx][yy]; continue;
            }
            dfs(xx, yy);
            dp[x][y] += dp[xx][yy];
        }
    }
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    fill(&dp[0][0], &dp[n - 1][m - 1], -1);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) cin >> g[i][j];
    
    dp[n - 1][m - 1] = 1; dfs(0, 0);
    cout << dp[0][0] << endl;
    return 0;
}

