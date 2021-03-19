#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <queue>
#include <string>
#include <stack>
#include <map>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer; stack<int> s;
    for(int i = progresses.size() - 1; i >= 0; i--) s.push(i);
    
    while(!s.empty()){
        for(int i = 0; i < speeds.size(); i++)
            if(progresses[i] < 100) progresses[i] += speeds[i];
        int answerNum = 0;
        while(!s.empty()){
            int pos = s.top();
            if(progresses[pos] > 99){
                s.pop(); answerNum++;
            }else break;
        }
        if(answerNum) answer.push_back(answerNum);
    }
    return answer;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solution({93, 30, 55}, {1, 30, 5});
    return 0;
}

