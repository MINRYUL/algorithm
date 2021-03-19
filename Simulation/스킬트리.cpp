#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <queue>
#include <string>
#include <map>

using namespace std;
map<char, int> m;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0, num = 0;
    for(int i = 0; i < skill.size(); i++) m.insert({skill[i], 1});
    
    for(int i = 0; i < skill_trees.size(); i++){
        int n = 0; bool check = true;
        for(int j = 0; j < skill_trees[i].size(); j++){
            if(m.count(skill_trees[i][j])){
                if(skill_trees[i][j] != skill[n++]){
                    check = false; break;
                }
            }
        }
        if(check) answer++;
    }
    return answer;
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solution("CBA", {"ABC", "CWEDA", "AXSWEDB", "ASDWBFEC"});
    return 0;
}

