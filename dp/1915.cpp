#include <cstdio>
#include <algorithm>

using namespace std;
int n, m, r, result = 1, sq[1002][1002];

int main(int argc, const char * argv[]) {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) scanf("%1d", &sq[i][j]);
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(sq[i][j] > r) r = sq[i][j];
            if(sq[i - 1][j - 1] && sq[i - 1][j] && sq[i][j - 1] && sq[i][j]){
                int t = min({sq[i - 1][j - 1], sq[i - 1][j], sq[i][j - 1]});
                sq[i][j] = t + 1;
                if(sq[i][j] > r) r = sq[i][j];
            }
        }
    }
    int temp = 3;
    for(int i = 1; i < r; i++){
        result += temp; temp += 2;
    }
    if(n == 1 && m == 1) printf("%d", sq[n][m]);
    else if(!r) printf("0");
    else printf("%d", result);
    return 0;
}

