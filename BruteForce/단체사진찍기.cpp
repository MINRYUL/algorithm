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
#include <stdlib.h>

using namespace std;

int r;
bool visited[9];
vector<string> d;
string sum, s;
bool findData(){
    for(string ch : d) {
        int pos1 = sum.find(ch[0]), pos2 = sum.find(ch[2]);
        int check = abs(pos1 - pos2) - 1;
        if(ch[3] == '=' && check != ch[4] - '0') return false;
        else if(ch[3] == '<' && check >= ch[4] - '0') return false;
        else if(ch[3] == '>' && check <= ch[4] - '0') return false;
    }
    return true;
}

void dfs(){
    if(sum.size() == 8 && findData()){ r++; return; }
    for(int i = 0; i < 8; i++){
        if(visited[i]) continue;
        visited[i] = true; sum.push_back(s[i]);
        dfs();
        visited[i] = false; sum.pop_back();
    }
}

int solution(int n, vector<string> data) {
    memset(visited, false, sizeof(visited));
    r = 0; d = data; sum = ""; s = "ACFJMNRT"; dfs();
    return r;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cout << solution(2, {""}) << endl;
    return 0;
}


