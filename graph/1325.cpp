#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <queue>
#include <string>
#include <stack>
#include <cmath>
#include <map>
#include <queue>
#include <stdlib.h>
#define MAX 10001
using namespace std;
int n, m, x, y, result;
vector<int> g[MAX], sequence;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    
    for(int i = 0; i < m; i++){
        cin >> x >> y;
        g[y].push_back(x);
    }
    for(int i = 1; i <= n; i++){
        queue<int> q; q.push(i);
        bool v[MAX] = {false, };
        v[i] = true; int r = 0;
        while(!q.empty()){
            int k = q.front(); q.pop(); r++;
            for(int j : g[k]){
                if(!v[j]){ q.push(j); v[j] = true; }
            }
        }
        if(result <= r){
            if(result == r) sequence.push_back(i);
            else {
                sequence.clear();
                sequence.push_back(i);
                result = r;
            }
        }
    }
    
    for(int i : sequence) cout << i << ' ';
    return 0;
}
