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

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> tempRe;
    bool v[31] = {false, };
    memset(v, true, sizeof(v));
    for(int i : lost) v[i] = false;
    
    sort(reserve.begin(), reserve.end());
    
    for(int i : reserve) {
        if(!v[i]) v[i] = true;
        else tempRe.push_back(i);
    }
        
    for(int i : tempRe){
        if((i - 1) == 0){
            v[i + 1] = true; continue;
        }
        if((i + 1) == n + 1){
            v[i - 1] = true; continue;
        }
        
        if(!v[i - 1]) v[i - 1] = true;
        else v[i + 1] = true;
    }
    
    for(int i = 1; i <= n; i++) if(v[i]) answer++;
    
    return answer;
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    return 0;
}
