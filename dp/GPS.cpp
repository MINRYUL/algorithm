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

// dp[i][j] => i번째 gps로그값이 j일 때, 최소 수정 횟수

#define INF 987654321

int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
    int answer = INF;
    int dp[101][202] = {INF, };
    
    for(int i = 0; i < 101; i++) fill(dp[i], dp[i] + 201, INF);
    
    vector<int> graph[201];
    for(vector<int> i : edge_list) {
        graph[i[0]].push_back(i[1]);
        graph[i[1]].push_back(i[0]);
    }
    
    dp[0][gps_log[0]] = 0;
    
    for(int i = 1; i < k; i++) {
        for(int j = 1; j < n + 1; j++){
            int x = gps_log[i] == j ? 0 : 1;
            
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + x);
            
            for(int e: graph[j]){
                dp[i][j] = min(dp[i - 1][e] + x, dp[i][j]);
            }
        }
    }
    int x = gps_log.back();
    for(int e: graph[x]) answer = min(answer, dp[k - 2][e]);
    answer = (answer > k - 2) ? -1 : answer;
    
    return answer;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cout << solution(7, 10, {{1, 2}, {1, 3}, {2, 3}, {2, 4}, {3, 4}, {3, 5}, {4, 6}, {5, 6}, {5, 7}, {6, 7}}, 6, {1, 2, 3, 3, 6, 7}) << endl
    ;
    return 0;
}


