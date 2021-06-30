#include <string>
#include <vector>
#include <unordered_map>
#include <list>
#include <iostream>
#include <sstream>
#include <algorithm>

//효율성 0점 수정필요

using namespace std;

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;
 
    while (getline(ss, temp, delimiter)) answer.push_back(temp);
 
    return answer;
}

void backtracking(unordered_map<string, list<int>> &m, vector<string> &splitInfo, bool visited[], int index, int scoreIndex){
    string s;
    for(int i = 0; i < 4; i++){
        if(visited[i]) s.append(splitInfo[i]);
    }
    if(s.size()){
        if(!m.count(s)){
            list<int> l; l.push_front(scoreIndex);
            m[s] = l;
        }
        else {
            list<int> &l = m[s];
            if(l.front() != scoreIndex)
                l.push_front(scoreIndex);
        }
    }
    
    for(int i = index; i < 4; i++){
        if(!visited[i]){
            visited[i] = true;
            backtracking(m, splitInfo, visited, index + 1, scoreIndex);
            visited[i] = false;
        }
    }
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer; int score[50001] = {0, };
    unordered_map<string, list<int>> m;
    
    for(int i = 0; i < info.size(); i++){
        bool visited[4] = {false, };
        vector<string> splitInfo = split(info[i], ' ');
        score[i] = stoi(splitInfo[4]);
        backtracking(m, splitInfo, visited, 0, i);
    }
    
    for(int i = 0; i < query.size(); i++){
        vector<string> queryInfo = split(query[i], ' ');
        string s;
        for(int j = 0; j < 7; j += 2)
            if(queryInfo[j][0] != '-') s.append(queryInfo[j]);
        
        int num = 0;
        if(s.size()){
            list<int> &l = m[s];
            if(queryInfo[7][0] != '-'){
                for(int i : l)
                    if(score[i] >= stoi(queryInfo[7])) num++;
            } else num = l.size();
        } else {
            if(queryInfo[7][0] != '-'){
                for(int i = 0; i < info.size(); i++)
                    if(score[i] >= stoi(queryInfo[7])) num++;
            } else num = info.size();
        }
        answer.push_back(num);
    }
    
    return answer;
}
