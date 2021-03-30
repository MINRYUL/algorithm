#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <queue>
#include <string>
#include <stack>
#include <map>
#include <queue>

using namespace std;

int solution(int n) {
    int dp[100001] = {0, };
    dp[0] = 0; dp[1] = 1;
    for(int i = 2; i <= n; i++)
        dp[i]  = ( dp[i - 2] % 1234567 + dp[i - 1] % 1234567 ) % 1234567;
    
    return dp[n];
}


int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cout << solution(100000) << endl;
    return 0;
}


