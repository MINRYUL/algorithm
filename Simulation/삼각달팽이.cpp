#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <queue>
#include <string>
#include <stack>
#include <map>

using namespace std;
int arr[11][11];

void recu(int I, int startI, int startJ, int num){
    if(I < 1) return;
    int tempX = 0, tempY = 0;
    for(int i = startI; i < startI + I; i++){
        arr[i][startJ] = num++;
        if(i == startI + I - 1){
            for(int j = startJ + 1; j < startJ + I; j++) arr[i][j] = num++;
            tempX = startI + I - 1; tempY = startJ + I - 1;
            for(int j = 0; j < I - 2; j++)
                arr[--tempX][--tempY] = num++;
        }
    }
    recu(I - 3, tempX + 1, tempY, num);
}

vector<int> solution(int n) {
    vector<int> answer;
    recu(n, 0, 0, 1);
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(arr[i][j]) answer.push_back(arr[i][j]);
            else break;
        }
    }
    return answer;
}


int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solution(5);
    return 0;
}

