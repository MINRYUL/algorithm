#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> candidateList;

bool cmp(string a, string b){
    if(a.size() >= b.size()) return true;
    return false;
}

void backtracking(vector<vector<string>> &relation, vector<int> &indexList, bool visited[], int index){
    if(indexList.size()){
        map<string, int> m; bool candidate = true;
        for(int i = 0; i < relation.size(); i++){
            string s;
            for(int j : indexList) s.append(relation[i][j]);
            
            if(!m.count(s)) m[s] = 1;
            else{ candidate = false; break; }
        }
    
        if(candidate) {
            string s;
            for(int i : indexList) s.push_back(i + '0');
            candidateList.push_back(s);
        }
    }
    
    for(int i = index; i < relation[0].size(); i++){
        if(!visited[i]){
            indexList.push_back(i);
            visited[i] = true;
            backtracking(relation, indexList, visited, i);
            indexList.pop_back();
            visited[i] = false;
        }
    }
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    vector<int> indexList;
    bool visited[9] = {false, };
    
    backtracking(relation, indexList, visited, 0);
    sort(candidateList.begin(), candidateList.end(), cmp);
    
    for(int i = 0; i < candidateList.size() - 1; i++){
        map<char, int> m; bool check = true;
        for(char a : candidateList[i]) m[a] = 1;
        for(int j = i + 1; j < candidateList.size(); j++){
            int num = 0;
            for(char c : candidateList[j])
                if(m.count(c)) num++;
            
            if(candidateList[j].size() == num){
                check = false; break;
            }
        }
        if(check) answer++;
    }
    return answer + 1;
}
