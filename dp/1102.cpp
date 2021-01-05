//#include<bits/stdc++.h>
#include <stdio.h>
#include <limits.h>
#include <algorithm>
#include <iostream>
using namespace std;
int n, p, x, ans, num;
int cost[16][16], mask[1 << 16];
char c, check[16];

int masking(int stat, int v){
    if(v == p)  return 0;
    
    int& ref = mask[stat];
    if(ref != -1)   return ref;
    ref = INT_MAX;
    
    for(int i = 0; i < n; i++){
        if(stat&(1 << i)){
            for(int j = 0; j < n; j++){
                if(i == j)  continue;
                if(!(stat & (1 << j)))
                    ref = min(ref, masking(stat | (1 << j), v + 1) + cost[i][j]);
            }
        }
    }

    return ref;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> x; cost[i][j] = x;
        }
    }
    x = 0;
    for(int i = 0; i < n; i++){
        cin >> c; check[i] = c;
        if(c == 'Y'){ num += 1; x |= (1 << i); }
    }
    cin >> p;
    memset(mask, -1, sizeof(mask));
    
    if(!num){
        if(!p)  cout << 0 << endl;
        else cout << -1 << endl;
    }else if(num >= p) cout << 0 << endl;
    else cout << masking(x, num) << endl;
    return 0;
}
