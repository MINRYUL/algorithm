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
#define MAX 12
using namespace std;
int n, m, x, y, z, r[MAX];

int getParent(int x){
    if(r[x] == x) return x;
    return r[x] = getParent(r[x]);
}
int unionParent(int a, int b){
    a = getParent(a); b = getParent(b);
    if(a < b){ r[b] = a; return a; }
    else{ r[a] = b; return b; }
}
int findParent(int a, int b){
    a = getParent(a); b = getParent(b);
    if(a == b) return 1;
    return 0;
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i <= n; i++) r[i] = i;
    for(int i = 0; i < m; i++){
        cin >> x >> y >> z;
        if(!x) unionParent(y, z);
        else{
            if(findParent(y, z)) cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }
    }
    return 0;
}
