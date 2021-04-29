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
int keySize, lockSize, boardSize;

void _rotate(vector<vector<int>> &key){
    vector<vector<int>> temp(keySize, vector<int>(keySize, 0));
    for(int i = 0; i < keySize; i++)
        for(int j = 0; j < keySize; j++) temp[i][j] = key[keySize - j - 1][i];
        
    key = temp;
}

bool check(vector<vector<int>> key, vector<vector<int>> board, int startX, int startY){
    for(int i = startX; i < startX + keySize; i++)
        for(int j = startY; j < startY + keySize; j++)
            board[i][j] += key[i - startX][j - startY];
    
    for (int i = keySize - 1; i <= boardSize - keySize; i++)
          for (int j = keySize - 1; j <= boardSize - keySize; j++)
            if(board[i][j] != 1) return false;
          
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    keySize = key.size(); lockSize = lock.size();
    boardSize = lockSize + (keySize - 1) * 2;
    vector<vector<int>> board(boardSize, vector<int>(boardSize, 0));
    for(int i = 0; i < lockSize; i++)
        for(int j = 0; j < lockSize; j++)
            board[i + keySize - 1][j + keySize - 1] += lock[i][j];
    
    for(int cut = 0; cut < 3; cut++){
        _rotate(key);
        
        for(int i = 0; i <= boardSize - keySize; i++)
            for(int j = 0; j <= boardSize - keySize; j++)
                if(check(key, board, i, j)) return true;
    }
    
    return false;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    return 0;
}


