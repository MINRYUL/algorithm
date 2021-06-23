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
#include <stack>
using namespace std;

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;
 
    while (getline(ss, temp, delimiter)) answer.push_back(temp);
 
    return answer;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> m;
    
    for(string s : record) {
        vector<string> result = split(s, ' ');
        if(!m.count({result[1]})) m.insert({result[1], result[2]});
        if(result[0] == "Change" || result[0] == "Enter"){
            m[result[1]] = result[2];
        }
    }
    
    string enter = "님이 들어왔습니다.";
    string leave = "님이 나갔습니다.";
    
    for(string s : record) {
        vector<string> result = split(s, ' ');
        string add = m[result[1]];
        if(result[0] == "Enter"){
            add.append(enter);
            answer.push_back(add);
        } else if(result[0] == "Leave"){
            add.append(leave);
            answer.push_back(add);
        }
    }
    
    return answer;
}
