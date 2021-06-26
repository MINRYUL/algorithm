#include <string>
#include <vector>
#include <cctype>
#include <map>
#include <iostream>

using namespace std;
vector<string> divideSet(string s){
    vector<string> set;
    for(int i = 1; i < s.size(); i++){
        string addSet; bool check = true;
        addSet.push_back(toupper(s[i - 1]));
        addSet.push_back(toupper(s[i]));
        for(char a : addSet)
            if(a < 'A' || a > 'Z') check = false;
        
        if(check)
            set.push_back(addSet);
    }
    return set;
}

vector<string> makeIntersectionSet(vector<string> str1, vector<string> str2){
    map<string, int> m;
    vector<string> result;
    for(int i = 0; i < str1.size(); i++){
        if(!m.count(str1[i])) m[str1[i]] = 2;
        else{
            int add = m[str1[i]];
            m[str1[i]] = add + 1;
        }
    }
    
    for(int i = 0; i < str2.size(); i++){
        if(m.count(str2[i])) {
            if(m[str2[i]] == 1) continue;
            result.push_back(str2[i]);
            m[str2[i]] = m[str2[i]] - 1;
        }
    }
    return result;
}

int makeJoinedSet(vector<string> str1, vector<string> str2, vector<string> intersectionSet){
    map<string, int> m1, m2;
    vector<string> result;
    
    for(string s : intersectionSet){
        if(!m1.count(s)){
            m1[s] = 1; m2[s] = 1;
        } else{
            m1[s] = m1[s] + 1;
            m2[s] = m2[s] + 1;
        }
    }
    
    for(string s : str1){
        if(m1.count(s)) {
            if(!m1[s]) result.push_back(s);
            else m1[s] = m1[s] - 1;
        }
        else result.push_back(s);
    }
    
    for(string s : str2){
        if(m2.count(s)) {
            if(!m2[s]) result.push_back(s);
            else m2[s] = m2[s] - 1;
        }
        else result.push_back(s);
    }

    return result.size();
}

int solution(string str1, string str2) {
    int answer = 0;
    double joinedNum = 0, intersectionNum = 0;
    vector<string> strOneSet = divideSet(str1), strTwoSet = divideSet(str2);
    vector<string> intersectionSet;
    intersectionSet = makeIntersectionSet(strOneSet, strTwoSet);
    intersectionNum = intersectionSet.size();
    joinedNum = makeJoinedSet(strOneSet, strTwoSet, intersectionSet) + intersectionNum;
    
    if(!joinedNum) return 65536;
    double temp = intersectionSet.size()/joinedNum;
    answer = temp * 65536;
    return answer;
}
