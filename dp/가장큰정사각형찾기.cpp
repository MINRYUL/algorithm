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

using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;
    
    for(int i = 0; i < board.size(); i++)
        if(board[i][0]) answer = 1;
    for(int i = 0; i < board[0].size(); i++)
        if(board[0][i]) answer = 1;
    
    for(int i = 1; i < board.size(); i++){
        for(int j = 1; j < board[i].size(); j++){
            if(!board[i][j]) continue;
            int x = min({board[i - 1][j - 1], board[i - 1][j], board[i][j - 1]}) + 1;
            board[i][j] = max(x, board[i][j]);
            answer = max(board[i][j], answer);
        }
    }
    
    return answer * answer;
}


int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    return 0;
}


