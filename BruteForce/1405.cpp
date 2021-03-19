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
int n, graph[51][51];
double result, di[4];
int dx[4] = {0, 0, -1, 1},
    dy[4] = {-1, 1, 0, 0};

void dfs(int C, int x, int y, double cost){
    if(C == n){ result += cost; return; }
    for(int i = 0; i < 4; i++){
        int xx = x + dx[i], yy = y + dy[i];
        if(!graph[xx][yy]){
            graph[xx][yy] = 1; dfs(C + 1, xx, yy, cost * (di[i]/100));
            graph[xx][yy] = 0;
        }
    }
}

int main(void) {
    ios :: sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> n >> di[0] >> di[1] >> di[2] >> di[3];
    graph[15][15] = 1; dfs(0, 15, 15, 1);
    cout.precision(11); cout << result << endl;
    return 0;
}
