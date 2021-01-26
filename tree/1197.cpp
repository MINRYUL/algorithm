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
#define MAX 10001
using namespace std;
int v, e, x, y, z, sum, r[MAX];
struct Pos{ int x, y; };
vector<pair<int, Pos>> g;

bool compare(pair<int, Pos> a, pair<int, Pos> b) {
    return a.first < b.first;
}

int getParent(int a){
    if(r[a] == a) return a;
    return r[a] = getParent(r[a]);
}

void unionSum(int a, int b){
    a = getParent(a); b = getParent(b);
    if(a < b) r[b] = a;
    else r[a] = b;
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> v >> e;
    for(int i = 0; i < e; i++){
        cin >> x >> y >> z;
        Pos p = {x, y};
        g.push_back({z, p});
    }
    sort(g.begin(), g.end(), compare);
    for(int i = 0; i <= v; i++) r[i] = i;
    for(pair<int, Pos> i : g){
        int a = getParent(i.second.x), b = getParent(i.second.y);
        if(a == b) continue;
        else{
            unionSum(a, b); sum += i.first;
        }
    }
    cout << sum << endl;
    return 0;
}
