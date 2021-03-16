#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <queue>
#include <string>

using namespace std;
int arr[3] = {4, 1, 2};

string solution(int n) {
    string answer = "";
    while(n){
        int temp = n%3;
        answer.push_back(arr[temp] + '0');
        n /= 3;
        if(!temp) n--;
    }
    reverse(answer.begin(), answer.end());
    return answer;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    solution(4);
    return 0;
}

