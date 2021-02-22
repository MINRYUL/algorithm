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
using namespace std;
int n, x, y, r;
pair<int, int> arr[9];

void dfs(int I){
    if(I == n){
        int temp = 0;
        for(int i = 0; i < n; i++)
            if(arr[i].first <= 0) temp++;
        if(r < temp) r = temp;
        return;
    }
    if(arr[I].first <= 0){ dfs(I + 1); return; }
    bool check = false;
    for(int i = 0; i < n; i++){
        if(i == I) continue;
        int temp = arr[I].first, temp2 = arr[i].first;
        if(arr[i].first > 0){
            arr[I].first -= arr[i].second; arr[i].first -= arr[I].second; check = true;
        }else continue;
        dfs(I + 1); arr[I].first = temp; arr[i].first = temp2;
    }
    if(!check) dfs(I + 1);
}
int main(void) {
    ios :: sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x >> y; arr[i] = {x, y};
    }
    dfs(0);
    cout << r << endl;
    return 0;
}
