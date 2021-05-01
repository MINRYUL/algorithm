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

bool cmp(vector<int> &a, vector<int> &b) {
    if(a[2] < b[2]) return true;
    return false;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<int> graph[102];
    
    sort(costs.begin(), costs.end(), cmp);
    
    for(vector<int> i : costs){
        bool visited[102] = {false, };
        queue<pair<int, int>> q; q.push({i[0], -1});
        graph[i[0]].push_back(i[1]);
        graph[i[1]].push_back(i[0]);
        visited[i[0]] = true;
        bool c = true;
        while(!q.empty()){
            pair<int, int> x = q.front(); q.pop();
            for(int i : graph[x.first]){
                if(i == x.second) continue;
                if(visited[i]){ c = false; break; }
                visited[i] = true;
                q.push({i, x.first});
            }
            if(!c) break;
        }
        if(!c){
            graph[i[0]].pop_back();
            graph[i[1]].pop_back();
        }else answer += i[2];
    }
    
    return answer;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solution(4, {{0,1,1}, {0,2,2}, {1,2,5}, {1,3,1}, {2,3,8}});
    return 0;
}


