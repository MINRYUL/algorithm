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

int solution(int n) {
    int answer = 0, sum = 0, pos = 1;
    for(int i = 1; i <= n; i++){
        sum += i;
        if(sum == n) answer++;
        else if(sum > n){
            int temp = pos;
            for(int j = pos; j < i; j++){
                sum -= j; temp++;
                if(sum == n) answer++;
                else if(sum < n) break;
            }
            pos = temp;
        }
    }
    return answer;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cout << solution(15);
    return 0;
}

