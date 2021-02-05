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
vector<int> v;
bool visited[50];
int n, x;

void dfs(int I, int C){
    if(C == 6){
        vector<int> r;
        for(int i = 0; i < n; i++){
            if(visited[v[i]]) r.push_back(v[i]);
        }
        sort(r.begin(), r.end());
        for(int i : r) cout << i << ' ';
        cout << '\n';
    }
    for(int i = I; i < n; i++){
        if(visited[v[i]]) continue;
        visited[v[i]] = true;
        dfs(i, C + 1);
        visited[v[i]] = false;
    }
}

int main(int argc, const char * argv[]) {
    while(1){
        cin >> n; if(!n) return 0;
        v.clear(); memset(visited, false, sizeof(visited));
        for(int i = 0; i < n; i++){
            cin >> x; v.push_back(x);
        }
        dfs(0, 0);
        cout << '\n';
    }
    
}
