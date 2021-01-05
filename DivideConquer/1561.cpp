//#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 10001
using namespace std;
long long n;
int m, arr[MAX], ans;

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++) cin >> arr[i];
    
    long long left = 0, right = 2000000000LL * 10000LL, result;
    
    while(left <= right){
        long long mid = (left + right)/2, cal = m;
        for(int i = 0; i < m; i++) cal += mid/(long long)arr[i];
        if(cal < n) left = mid + 1;
        else right = mid - 1, result = cal;
    }
    
    for(int i = m - 1; i >= 0; i--){
        if(!(left % arr[i])){
            if(result == n){ ans = i; break; }
            else result--;
        }
    }
    cout << ans + 1 << endl;
    return 0;
}
