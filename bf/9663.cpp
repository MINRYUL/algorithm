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
#define MAX 101
using namespace std;
int n, r, o, c[16];

void dfs(int I){
    if(n == I) r++;
    else{
        for(int i = 0; i < n; i++){
            c[I] = i; o = 0;
            for(int j = 0; j < I; j++){
                if(c[j] == c[I] || abs(c[I] - c[j]) == (I - j)){
                    o = 1; break;
                }
            }
            if(!o) dfs(I + 1);
        }
    }
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n; dfs(0);
    cout << r;
}
