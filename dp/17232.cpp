//#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 101
using namespace std;

int n, m, t, k, a, b;
char arr[MAX][MAX];

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> t >> k >> a >> b;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) cin >> arr[i][j];
    
    while(t--){
        char temp[MAX][MAX] = { 0 }; int dp[MAX][MAX] = { 0 };
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                temp[i][j] = arr[i][j];
                if(arr[i][j] == '*') dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] + 1;
                else dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1];
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                temp[i][j] = arr[i][j]; int start1, end1, start2, end2;
                if(i - k < 1) start1 = 1;
                else start1 = i - k;
                if(i + k > n) end1 = n;
                else end1 = i + k;
                if(j - k < 1) start2 = 1;
                else start2 = j - k;
                if(j + k > m) end2 = m;
                else end2 = j + k;
                int life = dp[end1][end2] - dp[end1][start2 - 1] - dp[start1 - 1][end2] + dp[start1 - 1][start2 - 1];
                if(arr[i][j] == '*') life--;
                if(life < a || life > b) temp[i][j] = '.';
                if(arr[i][j] == '.')
                    if(a < life && life <= b) temp[i][j] = '*';
            }
        }
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++) arr[i][j] = temp[i][j];
        
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) cout << arr[i][j];
        cout << endl;
    }
    return 0;
}
