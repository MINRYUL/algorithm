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

using namespace std;

string solution(string s) {
    string answer = "";
    istringstream ss(s);
    string stringBuffer;
    vector<string> v;
    vector<int> num;
    
    while (getline(ss, stringBuffer, ' '))
        v.push_back(stringBuffer);

    for(string i : v)
        num.push_back(stoi(i));
    
    sort(num.begin(), num.end());
    
    answer.append(to_string(num[0]));
    answer.push_back(' ');
    answer.append(to_string(num[num.size() - 1]));
    return answer;
}


int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    return 0;
}


