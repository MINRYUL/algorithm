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

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int x = (brown - 4)/2;
    for(int i = 1; i < x/2 + 1; i++){
        if(i * (x - i) == yellow){
            answer.push_back(x - i + 2);
            answer.push_back(i + 2);
            break;
        }
    }
    return answer;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solution(24, 24);
    return 0;
}

