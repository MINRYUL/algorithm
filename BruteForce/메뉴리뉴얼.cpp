#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <queue>
#include <string>
#include <map>

using namespace std;
int n, arr[11]; bool visited[11], check[30]; string s;
map<char, int> m;
map<int, int> num;
map<string, int> ma;
vector<pair<string, int>> r;

void dfs(int I, int N, vector<string> orders){
    if(s.size() > n) return;
    if(s.size() > 1 && num.count(s.size())){
        int re = 1;
        for(int i = 0; i < orders.size(); i++){
            if(i == N) continue;
            int t = 0;
            for(int j = 0; j < s.size(); j++)
                if(orders[i].find(s[j]) != string::npos) t++;
            if(t == s.size()) re++;
        }
        if(re > 1 && arr[s.size()] <= re){
            string temp; temp.append(s);
            sort(temp.begin(), temp.end());
            if(!ma.count(temp)){
                r.push_back({temp, re}); ma.insert({temp, re});
                arr[s.size()] = re;
            }
        }
    }
    for(int i = I; i < n; i++){
        if(visited[i] || !m.count(orders[N][i])) continue;
        visited[i] = true; s.push_back(orders[N][i]);
        dfs(i, N, orders);
        visited[i] = false; s.pop_back();
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for(int i = 0; i < orders.size(); i++){
        for(int j = 0; j < orders[i].size(); j++){
            if(!check[orders[i][j] - 'A']) check[orders[i][j] - 'A'] = true;
            else m.insert({orders[i][j], 1});
        }
    }
    for(int i : course) num.insert({i, i});
    for(int i = 0; i < orders.size(); i++){
        n = orders[i].size(); s.clear();
        memset(visited, false, sizeof(visited));
        dfs(0, i, orders);
    }
    
    sort(r.begin(), r.end());
    for(pair<string, int> i : r)
        if(arr[i.first.size()] == i.second) answer.push_back(i.first);
    return answer;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solution({"AB", "CBA", "ABCD", "EDCBA", "ABCDEF", "GFEDCBA"}, {2, 3, 5});
    return 0;
}

