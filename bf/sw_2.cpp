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
#define MAX 100000
using namespace std;
int p, n, h, x, y, r;
vector<int> v[100];

void dfs(int sum, int d, int cut, int k){
    for(int j = 0; j < cut; j++){
        if(v[k][j] > d){
            if(r < sum) r = sum; return;
        }else if(v[k][j] == d){
            r = h; return;
        }else dfs(sum + v[k][j], d - v[k][j], j, k);
    }
}

int main() {
    cin >> p >> n >> h; int check = 1;
    for(int i = 0; i < n; i++){
        cin >> x >> y; if(check != x) check++;
        v[x].push_back(y);
    }
    for(int i = 1; i <= check; i++){
        sort(v[i].begin(), v[i].end()); r = 0;
        for(int j = 0; j < v[i].size(); j++){
            if(v[i][j] > h) break;
            else if(v[i][j] == h) r = h;
            else{
                dfs(v[i][j], h - v[i][j],  j, i);
            }
        }
        cout << i << ' ' << r * 1000 << '\n';
    }
    
    return 0;
}
