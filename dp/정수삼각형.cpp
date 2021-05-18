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


int solution(vector<vector<int>> triangle) {
    int answer = 0;
    vector<vector<int>> dp;
    for(int i = 0; i < triangle.size(); i++){
        vector<int> temp;
        for(int j = 0; j < triangle[i].size(); j++) temp.push_back(triangle[i][j]);
        dp.push_back(temp);
    }
    
    for(int i = 0; i < triangle.size() - 1; i++){
        for(int j = 0; j < triangle[i].size(); j++){
            dp[i + 1][j] = max(dp[i + 1][j], triangle[i + 1][j] + dp[i][j]);
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], triangle[i + 1][j + 1] + dp[i][j]);
            answer = max({answer, dp[i + 1][j], dp[i + 1][j + 1]});
        }
    }
    
    return answer;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solution({{7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5}});
    return 0;
}


