#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <queue>
#include <string>
#include <stack>
#include <cmath>
#include <map>
#include <queue>
#include <stdlib.h>

using namespace std;

vector<int> graph[201];
bool visited[201];

void dfs(int x){
    visited[x] = true;
    for(int i : graph[x])
        if(!visited[i]) dfs(i);
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i = 0; i < computers.size(); i++){
        for(int j = 0; j < computers[i].size(); j++){
            if(i == j) continue;
            if(computers[i][j]){
                graph[i].push_back(j); graph[j].push_back(i);
            }
        }
    }
    
    memset(visited, false, sizeof(visited));
    
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            dfs(i); answer++;
        }
    }
    return answer;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cout << solution(3, {{1, 1, 0}, {1, 1, 1}, {0, 1, 1}}) << endl;
    return 0;
}


