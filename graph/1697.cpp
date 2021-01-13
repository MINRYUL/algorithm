//#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
#include <stack>
#include <cstring>
#define MAX 100002
using namespace std;
int n, k, graph[MAX];

int main(void) {
    cin.tie(NULL); ios::sync_with_stdio(false);
    cin >> n >> k;
    if(n == k){
        cout << 0 << endl; return 0;
    }
    queue<int> q; q.push(n); graph[n] = 1;
    while(!q.empty()){
        int x = q.front(); q.pop();
        for(int i : {1, -1}){
            if(x + i >= 0 && x + i <= 100000 && ((!graph[x + i]) || (graph[x + i] > graph[x] + 1))){
                q.push(x + i); graph[x + i] = graph[x] + 1;
            }
        }
        if(2 * x <= 100000 && (!graph[2 * x] || (graph[2 * x] > graph[x] + 1))){
            q.push(2 * x); graph[2 * x] = graph[x] + 1;
        }
    }

    cout << graph[k] - 1 << endl;
    return 0;
}
