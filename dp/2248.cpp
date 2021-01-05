//#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long I, dp[33][33];
string ans;
int N,L;

void sol(int N, int L, long long I) {
    if(N == 0) return;
    if(L == 0) {
        for(int i = 0; i < N; i++) ans += '0';
        return;
    }
    long long skip = 0;
    for(int i = 0; i <= L; i++) skip += dp[N-1][i];
    if(skip >= I) ans += '0', sol(N-1, L, I);
    else ans += '1', sol(N-1, L-1, I-skip);
    return;
}


int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> L >> I;
    dp[0][0] = 1;
    for(int i = 1; i < 33; i++) {
        dp[i][0] = 1; dp[i][i] = 1;
    }
    for(int i = 2; i <= N; i++)
        for(int j = 1; j <= i; j++)
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        
    sol(N, L, I); cout << ans << '\n';
    return 0;
}
