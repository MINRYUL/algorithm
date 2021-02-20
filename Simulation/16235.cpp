//#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm> //sort ..
#include <queue>
#include <string>
#include <map>
#include <stack>
#include <cmath> //pow, sqrt
#include <cstring> //memset
#include <utility> //pair
using namespace std;
int n, m, k, r, c, z, A[11][11], nourish[11][11], t[11][11];
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1},
    dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
vector<int> tree[11][11];

void year(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int sum = 0;
            if(t[i][j]){
                sort(tree[i][j].begin(), tree[i][j].end());
                vector<int> temp;
                while(!tree[i][j].empty()){
                    int c = tree[i][j].front();
                    tree[i][j].erase(tree[i][j].begin());
                    if(c <= nourish[i][j]){
                        nourish[i][j] -= c;
                        temp.push_back(c + 1);
                    }else{
                        sum += c/2; t[i][j] -= 1;
                    }
                }
                tree[i][j].insert(tree[i][j].begin(), temp.begin(), temp.end());
            }
            nourish[i][j] += sum;
        }
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            nourish[i][j] += A[i][j];
            if(t[i][j]){
                for(int num : tree[i][j]){
                    if(!(num % 5)){
                        for(int d = 0; d < 8; d++){
                            int xx = i + dx[d], yy = j + dy[d];
                            if(xx < 1 || yy < 1 || xx > n || yy > n) continue;
                            tree[xx][yy].push_back(1);
                            t[xx][yy] += 1;
                        }
                    }
                }
            }
        }
    }
    
}

int main(void) {
    ios :: sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> A[i][j]; nourish[i][j] = 5;
        }
    }
    for(int i = 0; i < m; i++){
        cin >> r >> c >> z;
        tree[r][c].push_back(z);
        t[r][c] += 1;
    }
    for(int i = 0; i < k; i++) year();
    int result = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) if(t[i][j]) result += t[i][j];
    cout << result << endl;
    return 0;
}
