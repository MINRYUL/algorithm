#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <queue>
#include <string>
#include <stack>
#include <cmath>
#include <map>
#include <queue>

using namespace std;
bool visited[31];
int answer;

void dfs(int I, int C, vector<int> v, int sum){
    if(C >= 1) answer += sum;
    if(C >= v.size()) return;
    
    for(int i = I; i < v.size(); i++){
        if(visited[i]) continue;
        visited[i] = true;
        if(!C) dfs(i, C + 1, v, v[i]);
        else dfs(i, C + 1, v, v[i] * sum);
        visited[i] = false;
    }
}

int solution(vector<vector<string>> clothes) {
    int num = 0;
    map<string, int> m;
    vector<int> v;
    for(int i = 0; i < clothes.size(); i++){
        if (!m.count(clothes[i][1])) {
            m.insert({clothes[i][1], num});
            v.push_back(1); num++;
        } else v[m.find(clothes[i][1]) -> second]++;
    }
    bool c = true;
    for(int i : v) if(i > 1) c = false;
    if(c) return pos(2, v.size()) - 1;
    dfs(0, 0, v, 0);
    return answer;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cout << solution({{"yellow_hat", "headgear"}, {"blue_sunglasses", "eyewear"}, {"green_turban", "headgear"}}) << endl;
    return 0;
}


