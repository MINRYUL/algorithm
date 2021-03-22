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

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end(), greater<>());
    int num = (int)citations.size()/2, cot = 0; bool cut = false;
    if(!(citations.size() % 2)) num--;
    for(int i = num; i < citations.size(); i++){
        if(cut && cot == citations[i] && citations[i] == i + 1){
            answer++; continue;
        }else if(!cut){
            if(citations[i] <= i + 1){
                if(i == num) answer = min(i + 1, citations[i]);
                else answer = i;
                cut = true; cot = citations[i];
            }
        }
    }
    if(!citations[0]) return 0;
    if(!answer) return (int)citations.size();
    return answer;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cout << solution({ 0, 0, 0 }) << endl;
    return 0;
}

