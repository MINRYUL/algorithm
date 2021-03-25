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

int getOneCount(int n){
    int oneNum = 0;
    while(n){
        int x = n % 2;
        if(x) oneNum++;
        n /= 2;
    }
    return oneNum;
}

int solution(int n) {
    int oneNum = getOneCount(n);
    while(n++)
        if(oneNum == getOneCount(n))  return n;
    
    return 0;
}


int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solution(15);
    return 0;
}

