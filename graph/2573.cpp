//#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 301
using namespace std;
int n, m, z, result, arr[MAX][MAX];
bool c, cha[MAX][MAX];

void DFS(int x, int y){
    if(x > 0 && cha[x - 1][y] > 0 && cha[x - 1][y]){ cha[x][y] = false; DFS(x - 1, y); }
    if(x < n - 1 && cha[x + 1][y] > 0 && cha[x + 1][y]){ cha[x][y] = false; DFS(x + 1, y); }
    if(y > 0 && cha[x][y - 1] > 0 && cha[x][y - 1]){ cha[x][y] = false; DFS(x, y - 1); }
    if(y < m - 1 && cha[x][y + 1] > 0 && cha[x][y + 1]){ cha[x][y] = false; DFS(x, y + 1); }
    cha[x][y] = false;
}

void find(){
    int x, y; x = y = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] > 0){
                if(i > 0 && !arr[i - 1][j]) --arr[i][j];
                if(i < n - 1 && !arr[i + 1][j]) --arr[i][j];
                if(j > 0 && !arr[i][j - 1]) --arr[i][j];
                if(j < m - 1 && !arr[i][j + 1]) --arr[i][j];
                if(arr[i][j] <= 0)  arr[i][j] = -1;
                else{ x = i; y = j; cha[i][j] = true; }
            }
        }
    }
    if(!c)  DFS(x, y);
    int check = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] == -1) arr[i][j] = 0;
            if(cha[i][j] == true)  c = true;
            if(!arr[i][j]) ++check;
        }
    }
    if(c == true || check == n*m){ if(c == true) ++result;  return; }
    else{ ++result; find(); }
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++)  for(int j = 0; j < m; j++)  cin >> arr[i][j];
        
    find();
    if(c) cout << result << endl;
    else cout << 0 << endl;
    return 0;
}
