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

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i : scoville) pq.push(i);
    bool c = false; int temp = 0;
    while(!pq.empty()){
        int x = pq.top();
        if(x > K){ c = true; break; }
        pq.pop();
        if(pq.empty()){ c = false; break; }
        int y = pq.top(); pq.pop();
        temp = x + y * 2;
        pq.push(temp); answer++;
    }
    if(temp < K) c = false;
    
    if(!c) return -1;
    return answer;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    return 0;
}

