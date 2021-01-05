//#include<bits/stdc++.h>
#include <stdio.h>
#include <limits.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <math.h>
#define MAX 4000001
using namespace std;
vector<int> v;
int start, ans;
long long n, sum;
bool arr[MAX];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    
    for(int i = 2; i <= sqrt(n); i++) {
        if (arr[i]) continue;
        for(int j = i + i; j <= n; j += i) arr[j] = true;
    }
    for(int i = 2; i <= n; i++)
        if(!arr[i]) v.push_back(i);
    
    for(int i = 0; i < v.size(); i++){
        sum += v[i];
        while(sum > n)
            sum -= v[start++];
        if(sum == n){ ans += 1; sum -= v[start++]; }
    }
    
    cout << ans << endl;

    return 0;
}
