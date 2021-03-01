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
int n, arr[201], dp[201];

int main() {
    ios :: sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    for(int i = 1; i <= n; i++) {
        if(dp[i] == 0) dp[i] = 1;
        for(int j = 1; j < i; j++)
            if(arr[i] > arr[j] && dp[i] < dp[j] + 1) dp[i] = dp[j] + 1;
    }
    sort(dp, dp + n + 1);
    cout << n - dp[n] << endl;
    return 0;
}
