#include<bits/stdc++.h>
#define MAX 300001
using namespace std;
long long N, D, G;
vector<int> tree[MAX];
bool visited[MAX];

void dfs(int start){
    visited[start] = true; bool check = false; unsigned long adder = 1;
    unsigned long x = tree[start].size();
    if(x >= 2){
        adder = x - 1; check = true;
        if(x >= 3) G += (x * (x - 1) * (x - 2))/6;
    }
    for(int i : tree[start]){
        if(!visited[i]) {
            if(check && (tree[i].size() > 1)) {
                D += (tree[i].size() - 1) * adder;
            }
            dfs(i);
        }
    }
}

int main(void) {
    cin.tie(NULL); ios::sync_with_stdio(false);
    cin >> N; int x, y;
    for(int i = 0; i < N - 1; i++){
        cin >> x >> y;
        tree[x].push_back(y); tree[y].push_back(x);
    }
    dfs(1);
    
    if(D == G * 3) cout << "DUDUDUNGA" << endl;
    else if(D > G * 3) cout << "D" << endl;
    else cout << "G" << endl;
    return 0;
}
