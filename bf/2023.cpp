//#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm> //sort ..
#include <queue>
#include <string>
#include <map>
#include <stack>
#include <cmath>
#include <cstring> //memset
#include <utility> //pair
#define MAX 100000001
using namespace std;
int n, sub = 1, sieve[6] = {1, 2, 3, 5, 7, 9}, first[4] = {2, 3, 5, 7};
vector<int> v;

bool sieveFind(int M) {
    if(M < 2) return false;
        for(int i = 2; i <= sqrt(M); i++){
            if(M % i == 0) return false;
        }
    return true;
}

void dfs(int R, int S){
    if(!S){ v.push_back(R); return; }
    int temp, s;
    if(S == 1){
        for(int j = 1; j < 10; j++){
            temp = 0; s = 0; s = S * j; temp = s + R;
            if(temp >= sub * 10) return;
            if(sieveFind(temp/S)) dfs(temp, S/10);
        }
        return;
    }
    if(S == sub){
        for(int j : first){
            temp = 0; s = 0; s = S * j; temp = s + R;
            if(temp >= sub * 10) return;
            if(sieveFind(temp/S)) dfs(temp, S/10);
        }
        return;
    }
    for(int j : sieve){
        temp = 0; s = 0; s = S * j; temp = s + R;
        if(temp >= sub * 10) return;
        if(sieveFind(temp/S)) dfs(temp, S/10);
    }
    
}

int main(void) {
    cin >> n;
    for(int i = 1; i < n; i++) sub *= 10;
    dfs(0, sub); sort(v.begin(), v.end());
    for(int i : v) cout << i << '\n';
    return 0;
}
