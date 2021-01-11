//#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
#include <stack>
#include <cstring>
using namespace std;
long long int f, s, g, u, d, arr[1000001];

int main(void) {
    cin.tie(NULL); ios::sync_with_stdio(false);
    cin >> f >> s >> g >> u >> d;
    
    queue<long long int> q; q.push(s); arr[s] = 1;
    while(!q.empty()){
        long long int x = q.front(); q.pop();
        if((x + u) <= f && !arr[x + u]){
            q.push(x + u);
            if(!arr[x + u]) arr[x + u] = arr[x] + 1;
            else if(arr[x + u] > arr[x] + 1)
                arr[x + u] = arr[x] + 1;
        }
        if((x - d) > 0 && !arr[x - d]){
            q.push(x - d);
            if(!arr[x - d]) arr[x - d] = arr[x] + 1;
            else if(arr[x - d] > arr[x] + 1)
                arr[x - d] = arr[x] + 1;
        }
    }
    
    if(!arr[g]){
        cout << "use the stairs" << endl;
        return 0;
    }
    cout << arr[g] - 1 << endl;
    return 0;
}
