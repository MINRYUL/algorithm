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
int deleteZeroCut, binaryCut;

void recu(string s){
    string t;
    if(s == "1") return;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '1') t.push_back('1');
        else deleteZeroCut++;
    }
    int x = (int)t.size(); t.clear();
    while(x){
        t.push_back(x % 2 + '0');
        x /= 2;
    }
    
    if(t == "1") return;
    reverse(t.begin(), t.end()); binaryCut++;
    recu(t);
}

vector<int> solution(string s) {
    vector<int> answer;
    deleteZeroCut = 0; binaryCut = 0; recu(s);
    answer.push_back(binaryCut + 1); answer.push_back(deleteZeroCut);
    return answer;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solution("1111111");
    return 0;
}


