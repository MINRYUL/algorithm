//#include<bits/stdc++.h>
#include <iostream>
#include <vector>

#define MAX 101
#define INF 987654321

int a[MAX][MAX], ans[MAX][MAX];
int n, m;

using namespace std;
int main() {
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n >> m;
    
    while(m--){
        int from, to, cost;
        cin >> from >> to >> cost;
        if(!a[from][to])  a[from][to] = cost;
        else if(a[from][to] > cost) a[from][to] = cost;
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j) continue;
            else if(!a[i][j]) a[i][j] = INF;
        }
    }
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n ; j++)
            for(int k = 1; k <= n; k++)
                if(a[j][i] + a[i][k] < a[j][k]) a[j][k] = a[j][i] + a[i][k];
            
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(a[i][j] >= INF) cout << '0' << ' ';
            else cout << a[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
