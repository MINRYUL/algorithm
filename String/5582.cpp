//#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm> //sort ..
#include <queue>
#include <string>
#include <map>
#include <stack>
#include <cstring> //memset
#include <utility> //pair
#define MAX 4001
using namespace std;
int dp[MAX][MAX], r;
string s1, s2;

int main(void) {
    cin >> s1 >> s2;
    for(int i = 1; i <= s1.size(); i++){
        for(int j = 1; j <= s2.size(); j++){
            if(s1[i - 1] == s2[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
                r = max(dp[i][j], r);
            }
            else dp[i][j] = 0;
        }
    }
    
    cout << r << endl;
    return 0;
}
