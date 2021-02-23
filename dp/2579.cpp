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
int n, arr[301], dp[301];

int main(void) {
    ios :: sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    dp[0] = arr[0];
    dp[1] = max(arr[0] + arr[1], arr[1]);
    dp[2] = max(arr[0] + arr[2], arr[1] + arr[2]);

    for(int i = 3; i < n; i++) dp[i] = max(dp[i-2] + arr[i], dp[i-3] + arr[i-1] + arr[i]);
    
    cout << dp[n-1] << endl;
    return 0;
}
