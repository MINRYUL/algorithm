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
#include <cctype>

using namespace std;

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;
 
    while (getline(ss, temp, delimiter)) answer.push_back(temp);
 
    return answer;
}

string solution(string s) {
    string answer = "";
    vector<string> result = split(s, ' ');
    int maxCut = result.size() - 1, cut = 0;
    for(string s : result){
        transform(s.begin(), s.end(), s.begin(),
                  [](unsigned char c){ return tolower(c); });
        if('a' <= s[0] && s[0] <= 'z') s[0] -= 32;
        if(cut != maxCut) s.push_back(' ');
        answer.append(s);
        cut += 1;
    }
    
    char checkSpace = s[s.size() - 1];
    if(checkSpace == ' ') answer.push_back(' ');
    return answer;
}
