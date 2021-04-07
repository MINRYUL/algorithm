#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <queue>
#include <string>
#include <stack>
#include <map>
#include <queue>

using namespace std;


int solution(vector<int> people, int limit) {
    int answer = 0;
    int l = 0, r = people.size() - 1;
    sort(people.begin(), people.end(), greater<>());
    while(l <= r){
        if(l == r){ answer++; break; }
        else if(people[l] + people[r] > limit){
            answer++; l++;
        }else{
            answer++; l++; r--;
        }
    }
    
    return answer;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    return 0;
}


