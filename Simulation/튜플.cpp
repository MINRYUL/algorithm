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

bool cmp(const vector<int>& a, const vector<int>& b){
    if(a.size() < b.size()) return true;
    return false;
}

vector<int> split(string input, char delimiter) {
    vector<int> answer;
    stringstream ss(input);
    string temp;
    while (getline(ss, temp, delimiter)) answer.push_back(stoi(temp));
    return answer;
}

vector<int> solution(string s) {
    vector<int> answer; vector<string> cut; string add; map<int, int> m;
    for(int i = 1; i < s.size() - 1; i++){
        if(s[i] == '}') cut.push_back(add);
        else if(('0' <= s[i] && s[i] <= '9') || s[i] == ',') add.push_back(s[i]);
        else if(s[i] == '{') add.clear();
    }
    vector<vector<int>> conversion;
    
    for(string i : cut){
        vector<int> temp = split(i, ',');
        conversion.push_back(temp);
    }
    sort(conversion.begin(), conversion.end(), cmp);
    for(int i = 0; i < conversion.size(); i++){
        for(int j = 0; j < conversion[i].size(); j++){
            if(!m.count(conversion[i][j])){
                answer.push_back(conversion[i][j]);
                m.insert({conversion[i][j], 1});
            }
        }
    }
    return answer;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solution("{{2},{2,1},{2,1,3},{2,1,3,4}}");
    return 0;
}


