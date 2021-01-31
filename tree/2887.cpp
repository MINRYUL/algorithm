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
#define MAX 100001
using namespace std;
int n, x, y, z, r[MAX];
unsigned long long result;
struct Pos { int x, y, z; };
vector<pair<int, Pos>> v;
vector<pair<int, pair<int, int>>> g;

bool compare(pair<int, Pos> a, pair<int, Pos> b) {
    return a.second.x < b.second.x;
}
bool compare2(pair<int, Pos> a, pair<int, Pos> b) {
    return a.second.y < b.second.y;
}
bool compare3(pair<int, Pos> a, pair<int, Pos> b) {
    return a.second.z < b.second.z;
}

int getParent(int a){
    if(r[a] == a) return a;
    return r[a] = getParent(r[a]);
}

void unionSum(int a, int b){
    a = getParent(a); b = getParent(b);
    if(a < b) r[b] = a;
    else  r[a] = b;
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y >> z;
        Pos p = { x, y, z };
        v.push_back({ i, p });
    }
    for(int i = 0; i < MAX; i++) r[i] = i;
    
    sort(v.begin(), v.end(), compare);
    for(int i = 1; i < v.size(); i++){
        int t = abs(v[i - 1].second.x - v[i].second.x);
        g.push_back({t, {v[i - 1].first, v[i].first}});
        
    }
    sort(v.begin(), v.end(), compare2);
    for(int i = 1; i < v.size(); i++){
        int t = abs(v[i - 1].second.y - v[i].second.y);
        g.push_back({t, {v[i - 1].first, v[i].first}});
    }
    sort(v.begin(), v.end(), compare3);
    for(int i = 1; i < v.size(); i++){
        int t = abs(v[i - 1].second.z - v[i].second.z);
        g.push_back({t, {v[i - 1].first, v[i].first}});
    }

    sort(g.begin(), g.end());
    for(int i = 0; i < g.size(); i++){
        x = g[i].second.first; y = g[i].second.second;
        int cal = g[i].first;
        if(getParent(x) != getParent(y)){
            unionSum(x, y);
            result += cal;
        }
    }
    cout << result << endl;
    return 0;
}
