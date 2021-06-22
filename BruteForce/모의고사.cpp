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

bool cmp (pair<int, int> &a, pair<int, int> &b){
    if(a.first == b.first) return a.second <= b.second;
    return a.first > b.first;
}

vector<int> solution(vector<int> answers) {
    vector<int> r;
    int result[3] = {0, };
    int arrOne[5] = {1, 2, 3, 4, 5}, arrTwo[8] = {2, 1, 2, 3, 2, 4, 2, 5}, arrThree[10] = {3, 3, 1, 1, 2, 2 ,4, 4, 5, 5};
    
    for(int i = 0; i < answers.size(); i++){
        int currentAnswer = answers[i];
        if(arrOne[i % 5] == currentAnswer) result[0]++;
        if(arrTwo[i % 8] == currentAnswer) result[1]++;
        if(arrThree[i % 10] == currentAnswer) result[2]++;
    }
    
    vector<pair<int, int>> v = {{result[0], 1}, {result[1], 2}, {result[2], 3}};
    sort(v.begin(), v.end(), cmp);
    int temp = v[0].first;
    for(pair<int, int> i : v){
        if(temp == i.first) r.push_back(i.second);
    }
    
    return r;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    return 0;
}
