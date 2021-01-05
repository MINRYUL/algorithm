//#include<bits/stdc++.h>
#include <stdio.h>
#include <limits.h>
#include <algorithm>
using namespace std;

const static int INF = 987654321;
 
int n, cost[16][16], dp[16][1 << 16];
 
int func(int cur, int stat) {
    if (stat == ((1 << n) - 1)) {
        if (!cost[cur][0]) return INF;
        else return cost[cur][0];
    }
 
    int& ref = dp[cur][stat];
    if (ref) return ref;
    
    int m = INT_MAX - 16000001;
 
    for (int i = 1; i < n; ++i) {
        if (!(stat&(1 << i)) && cost[cur][i])
            m = min(m, func(i, (stat | (1 << i))) + cost[cur][i]);
    }
 
    return ref = m;
}
 
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            scanf("%d", &cost[i][j]);
 
    printf("%d", func(0, 1));
    return 0;
}
