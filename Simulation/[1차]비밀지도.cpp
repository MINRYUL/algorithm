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
#include <stack>
#include <cctype>

using namespace std;

string binary(int x, int y, int n){
    string s1, s2, s;
    
    while(x){
        if(x % 2) s1.push_back('#');
        else s1.push_back(' ');
        x /= 2;
    }
    
    while(s1.size() < n) s1.push_back(' ');
    
    while(y){
        if(y % 2) s2.push_back('#');
        else s2.push_back(' ');
        y /= 2;
    }
    
    while(s2.size() < n) s2.push_back(' ');
    
    for(int i = 0; i < n; i++){
        if(s1[i] == '#' || s2[i] == '#') s.push_back('#');
        else s.push_back(' ');
    }
    reverse(s.begin(), s.end());
    return s;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for(int i = 0; i < arr1.size(); i++)
        answer.push_back(binary(arr1[i], arr2[i], n));

    return answer;
}
