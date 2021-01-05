#include<bits/stdc++.h>
#define MAX 200001
using namespace std;
vector<int> rumor, graph[MAX];
int N, M, a, result[MAX];
bool visited[MAX];

void bfs(){
    queue<int> q;
    for(int i : rumor) q.push(i); vector<int> add; int c = 0;
    while(!q.empty()){
        int x = q.front(); q.pop();
        if(c != result[x]){
            for(int i : add) {
                visited[i] = true; result[i] = c + 1;
                add.clear();
            }
        }
        if(!add.size()) c = result[x];
        for(int i = 0; i < graph[x].size(); i++){
            int y = graph[x][i]; int believe = 0;
            if(visited[y]) continue;
            for(int j : graph[y]) if(visited[j]) believe++;
            if(believe * 2 >= graph[y].size() && !visited[y]){
                q.push(y); add.push_back(y);
            } else if(!visited[y]) result[y] = -1;
        }
    }
}

int main(void) {
    cin.tie(NULL); ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 1; i <= N; i++){
        while(cin >> a){
            if(a == 0) break;
            graph[i].push_back(a);
        }
    }
    cin >> M; memset(result, -1, sizeof(result));
    for(int i = 1; i <= M; i++){
        cin >> a; rumor.push_back(a);
        visited[a] = true; result[a] = 0;
    }
    bfs();
    for(int i = 1; i <= N; i++) cout << result[i] << ' ';
    return 0;
}
