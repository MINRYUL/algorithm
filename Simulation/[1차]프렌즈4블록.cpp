#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> rotateBoard(int m, int n, vector<string> &board){
    vector<string> result;
    
    for(int i = 0; i < n; i++){
        string add;
        for(int j = m - 1; j >= 0; j--)
            add.push_back(board[j][i]);
        result.push_back(add);
    }
    return result;
}

int solution(int m, int n, vector<string> board) {
    int answer = 0; bool nextCheck = true;
    int dx[3] = {1, 0, 1},
        dy[3] = {0, 1, 1};
    
    vector<string> roBoard = rotateBoard(m, n, board);
    
    while(nextCheck){
        nextCheck = false; vector<pair<int, int>> eraseList;
        queue<pair<int, int>> q; q.push({0, 0});
        for(int i = 0; i < (n - 1); i++){
            for(int j = 0; j < (m - 1); j++){
                if(roBoard[i][j] == ' ') continue;
                bool eraseBlock = true;
                for(int k = 0; k < 3; k++){
                    int nextX = dx[k] + i;
                    int nextY = dy[k] + j;
                    if(roBoard[i][j] != roBoard[nextX][nextY]){
                        eraseBlock = false; continue;
                    }
                }
                if(eraseBlock){
                    nextCheck = true; eraseList.push_back({i, j});
                }
            }
        }
        if(nextCheck){
            reverse(eraseList.begin(), eraseList.end());
            for(pair<int, int> i : eraseList){
                if(roBoard[i.first][i.second] != ' '){
                    roBoard[i.first][i.second] = ' '; answer += 1;
                }
                for(int j = 0; j < 3; j++){
                    if(roBoard[dx[j] + i.first][dy[j] + i.second] != ' '){
                        roBoard[dx[j] + i.first][dy[j] + i.second] = ' '; answer += 1;
                    }
                }
            }
            
            for(int i = 0; i < n; i++){
                string add;
                for(int j = 0; j < m; j++)
                    if(roBoard[i][j] != ' ') add.push_back(roBoard[i][j]);
                
                for(int k = add.size() - 1; k < n; k++)
                    add.push_back(' ');
                
                roBoard[i] = add;
            }
        }
    }
    
    return answer;
}


int main(){
    cout << solution(4, 5, {"CCBDE", "AAADE", "AAABF", "CCBBF"}) << endl;
    return 0;
};
