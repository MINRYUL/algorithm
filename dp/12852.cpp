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
#define MAX 1000001
using namespace std;
int N, t = 1, arr[MAX], g[MAX];
vector<int> r;
void dfs(int I, int C){
    if(I == 1 && arr[I] > C){
        arr[I] = C; r.clear(); t = 1;
        while(1){
            if(t == N) break;
            r.push_back(g[t]); t = g[t];
        }
        return;
    }
    arr[I] = C;
    if(I < 1 || arr[1] <= C) return;
    if(!(I % 2)){ g[I/2] = I; dfs(I/2, C + 1); }
    if(!(I % 3)){ g[I/3] = I; dfs(I/3, C + 1); }
    if(I > 1) g[I - 1] = I; dfs(I - 1, C + 1);
}

int main(void) {
    ios :: sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> N; fill(arr, arr + (N + 1), MAX); dfs(N, 0);
    cout << r.size() << '\n'; reverse(r.begin(), r.end()); r.push_back(1);
    for(int i : r) cout << i << ' ';
    return 0;
}
