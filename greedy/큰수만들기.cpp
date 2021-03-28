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

string solution(string number, int k) {
    string answer = "";
    pair<int, int> temp; int start = 0;
    if(number.size() == 1 && k == 1) return number;
    int maxL = number.size() - k;
    while(answer.size() != maxL){
        if(!k){
            for(int i = start; i < number.size(); i++)
                answer.push_back(number[i]);
            break;
        }
        int m = start + k;
        for(int i = start; i <= m; i++){
            if(!(number[i] - '0') && !temp.first) temp = {0, i};
            else if(temp.first < number[i] - '0') temp = {number[i] - '0', i};
        }
        answer.push_back(temp.first + '0');
        if(temp.second) k -= (temp.second - start);
        start = temp.second + 1;
        temp = {0, 0};
    }
    
    return answer;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cout << solution("000010000", 1) << endl;
    return 0;
}

