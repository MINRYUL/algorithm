#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <queue>
#include <string>
#include <map>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0; bool c = false;
    priority_queue<int> pq; queue<pair<int, int>> q;
    for(int i = 0; i < priorities.size(); i++){
        q.push({priorities[i], i}); pq.push(priorities[i]);
    }
    while(1){
        int prio = q.front().first, pos = q.front().second; q.pop();
        if(prio == pq.top()){
            answer++;
            if(location == pos) break;
            pq.pop();
        }else q.push({prio, pos});
    }
    return answer;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    return 0;
}

