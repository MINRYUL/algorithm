#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    int minNum = min(n, m); int ch = 1;
    vector<int> check;
    while(ch <= minNum){
        if(!(n % ch) && !(m % ch)) check.push_back(ch);
        ch++;
    }
    answer.push_back(check[check.size() - 1]);
    
    int tn = n, tm = m, cn = 2, cm = 2;
    bool c = false;
    while(tn != tm){
        if(tn < tm) tn = n * cn++;
        else{ tm = m * cm++; c = true; }
    }
    if(c) answer.push_back(tm);
    else answer.push_back(tn);
    return answer;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    return 0;
}

