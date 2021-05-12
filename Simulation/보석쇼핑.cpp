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

#define MAX 100001

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    int arr[MAX] = {0, }, gSize = 0, result = MAX, cut = 1, num = 0;
    queue<pair<string, int>> q;
    map<string, int> m;
    
    for(string i : gems) if(!m.count(i)) m.insert({i, cut++});
    gSize = m.size();
    
    for(int i = 0; i < gems.size(); i++){
        int ind = m.find(gems[i]) -> second;
        q.push({gems[i], i + 1});
        if(!arr[ind]) num++;
        arr[m.find(gems[i]) -> second] = i + 1;
        
        pair<string, int> x = q.front();
        while(x.second != arr[m.find(x.first) -> second]){
            q.pop();
            x = q.front();
        }
        
        if(num >= gSize){
            if(result > (i + 1) - x.second){
                result = (i + 1) - x.second;
                answer.clear();
                answer.push_back(x.second);
                answer.push_back(i + 1);
            }
        }
    }
    
    return answer;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    solution({"AA", "AB", "AC", "AA", "AC"});
    return 0;
}


