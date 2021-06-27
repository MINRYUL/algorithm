#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0, distance[51];
    vector<pair<int, int>> graph[51];
    bool visited[51] = {false, };
    
    for(int i = 0; i < road.size(); i++){
        graph[road[i][0]].push_back({road[i][1], road[i][2]});
        graph[road[i][1]].push_back({road[i][0], road[i][2]});
    }
    memset(distance, K + 1, sizeof(distance));
    queue<pair<int, int>> q;
    
    q.push({1, 0}); visited[1] = true; distance[1] = 0;
    while(!q.empty()){
        pair<int, int> x = q.front(); q.pop();
        for(pair<int, int> i : graph[x.first]){
            if(!visited[i.first] || distance[i.first] > x.second + i.second){
                q.push({i.first, x.second + i.second});
                visited[i.first] = true;
                distance[i.first] = x.second + i.second;
            }
        }
    }
    
    for(int i = 2; i <= N; i++)
        if(distance[i] <= K) answer += 1;

    return answer + 1;
}
