#include<bits/stdc++.h>

#define MAX 52
#define INF 987654321

using namespace std;

int n, ans, c[MAX][MAX], f[MAX][MAX];
vector<int> v[MAX];

int main() {
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    
    cin >> n;
    while(n--){
        char a, b; int x, from, to;
        cin >> a >> b >> x;
        if('A' <= a && a <= 'Z') from = a - 'A';
        else from = a - 'a' + 26;
        if('A' <= b && b <= 'Z') to = b - 'A';
        else to = b - 'a' + 26;
        
        c[from][to] += x;
        c[to][from] += x;
        v[from].push_back(to);
        v[to].push_back(from);
    }
    int S = 0, T = 'Z' - 'A';
    while(1){
        int prev[MAX], flow = INF;
        memset(prev, -1, sizeof(prev));
        
        queue<int> q; q.push(S);
        
        while(!q.empty()){
            int cur = q.front(); q.pop();
            for(int i : v[cur]){
                if(prev[i] != -1) continue;
                if(c[cur][i] - f[cur][i] > 0){
                    q.push(i); prev[i] = cur;
                    if(i == T)  break;
                }
            }
        }
        if(prev[T] == -1) break;
        
        for(int i = T; i != S; i = prev[i]) flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);
        
        for(int i = T; i != S; i = prev[i]){
            f[prev[i]][i] += flow; f[i][prev[i]] -= flow;
        }
        ans += flow;
    }
    
    cout << ans;
    return 0;
}
