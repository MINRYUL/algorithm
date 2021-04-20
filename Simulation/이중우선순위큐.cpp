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

vector<int> solution(vector<string> operations) {
    int cut = 0;
    priority_queue<int, vector<int>, greater<int>> gPq;
    priority_queue<int, vector<int>, less<int>> lPq;
    
    for(string i : operations){
        if(!cut){
            while(!gPq.empty()) gPq.pop();
            while(!lPq.empty()) lPq.pop();
        }
        if(i[0] == 'I'){
            cut++; string num = i.substr(2);
            gPq.push(stoi(num)); lPq.push(stoi(num));
        } else if(i[0] == 'D'){
            if(!cut) continue;
            if(i[2] == '1'){
                lPq.pop(); cut--;
            } else{
                gPq.pop(); cut--;
            }
        }
    }
    
    if(!cut) return {0, 0};
    return {lPq.top(), gPq.top()};
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solution({"I 4", "I 3", "I 2", "I 1", "D 1", "D 1", "D -1", "D -1", "I 5", "I 6"});
    
/*
1
3 4
 */
    return 0;
}


