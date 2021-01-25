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
#define MAX 201
using namespace std;
int n, m, x, r[MAX];

int getParent(int a){
    if(r[a] == a) return a;
    else return getParent(r[a]);
}

void joinSet(int a, int b){
    a = getParent(a); b = getParent(b);
    if(a < b) r[b] = a;
    else r[a]= b;
}
int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i <= n; i++) r[i] = i;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> x;
            if(x) joinSet(i, j);
        }
    }
    cin >> x;
    int p = getParent(x);
    for(int i = 1; i < m; i++){
        cin >> x;
        if(p != getParent(x)){
            cout << "NO" << '\n'; return 0;
        }
    }
    
    cout << "YES" << '\n';
    return 0;
}
