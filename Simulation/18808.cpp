#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
int n, m, k, r, c, result, arr[41][41], pos[11][11];
int dx[4] = {-1, 0, 1, 0},
    dy[4] = {0, -1, 0, 1};
bool visited[41][41];

void rotate() {
    int temp[11][11] = {0, };
    for(int i = 0; i < c; i++)
        for(int j = 0, l = r - 1; j < r; j++, l--) temp[i][j] = pos[l][i];
    int tmp = r;
    r = c; c = tmp;
    memmove(pos, temp, sizeof(pos));
}

bool check(int x, int y){
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            if(pos[i][j] && arr[i + x][j + y]) return false;
    return true;
}

void put(int x, int y){
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            if(pos[i][j]) arr[i + x][j + y] = 1;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> k;
    for(int i = 0; i < k; i++){
        cin >> r >> c; memset(pos, 0, sizeof(pos));
        for(int j = 0; j < r; j++)
            for(int z = 0; z < c; z++) cin >> pos[j][z];
        
        for(int N = 0; N < 4; N++){
            bool ch = false;
            for(int I = 0; I <= n - r; I++){
                for(int j = 0; j <= m - c; j++){
                    if(check(I, j)){
                        put(I, j); ch = true;
                        break;
                    }
                }
                if(ch) break;
            }
            if(!ch) rotate();
            else break;
        }
    }
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(arr[i][j]) result++;
    cout << result << endl;
    return 0;
}

