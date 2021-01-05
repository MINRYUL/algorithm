#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<math.h>
#include<map>
using namespace std;
int X[6] = {0,1,1,0,-1,-1};
int Y[6] = {1,1,-1,-1,-1,1};

map<pair<int,int>,int> a;
int N, result;

void dfs(int x, int y, int index, int pos, int n){
    if(a.count({x, y}) > 0){
        if(n == N) result += 1;
        return;
    }
    if(n > N) return;
    a[{x, y}] = 1;
    if(index % 2 == 1){
        if(pos == -1){
            dfs(x + X[1], y + Y[1], 2, -1, n + 1);
            dfs(x + X[3], y + Y[3], 0, 0, n + 1);
        }
        else if(pos == 0){
            dfs(x + X[1], y + Y[1], 2, -1, n + 1);
            dfs(x + X[5], y + Y[5], 2, 1, n + 1);
        }
        else{
            dfs(x + X[3], y + Y[3], 2, 0, n + 1);
            dfs(x + X[5], y + Y[5], 2, 1, n + 1);
        }
    }else{
        if(pos == -1){
            dfs(x + X[0], y + Y[0], 1, 0, n + 1);
            dfs(x + X[2], y + Y[2], 1, -1, n + 1);
        }
        else if(pos == 1){
            dfs(x + X[0], y + Y[0], 1, 0, n + 1);
            dfs(x + X[4], y + Y[4], 5, 1, n + 1);
        }
        else{
            dfs(x + X[2], y + Y[2], 5, -1, n + 1);
            dfs(x + X[4], y + Y[4], 5, 1, n + 1);
        }
    }
    a.erase({x, y});
    return;
}
int main(void) {
    cin >> N;
    a[{0, 0}] = 1;
    dfs(0, 1, 1, 0, 0);
    cout << result << endl;
    return 0;
}
