//#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#define MAX 2200
using namespace std;
int n, arr[MAX][MAX], ans[3];

bool same(int x, int y, int n) {
    for (int i=x; i<x+n; i++)
        for (int j=y; j<y+n; j++)
            if (arr[x][y] != arr[i][j]) return false;
    
    return true;
}

void sol(int x, int y, int n) {
    if (same(x, y, n)){ ans[arr[x][y] + 1] += 1; return; }
    int m = n/3;
    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++) sol(x+i*m, y+j*m, m);
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) cin >> arr[i][j];
    
    sol(0, 0, n);
    
    for(int i = 0; i < 3; i++) cout << ans[i] << endl;
    return 0;
}
