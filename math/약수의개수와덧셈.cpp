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

int solution(int left, int right) {
    int answer = 0;
    vector<int> prime[1001];
    
    for(int i = 1; i < 1001; i++)
        for(int j = left; j <= right; j++)
            if(j % i) prime[j].push_back(i);
    
    for(int i = left; i <= right; i++){
        if(prime[i].size() % 2) answer -= i;
        else answer += i;
    }
    
    return answer;
}
