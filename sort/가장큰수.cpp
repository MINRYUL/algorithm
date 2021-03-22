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

bool cmp(string a, string b){
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> num;
    for(int i : numbers) num.push_back(to_string(i));
    sort(num.begin(), num.end(), cmp);
    for(string i : num) answer.append(i);
    int check = atoi(answer.c_str());
    if(!check || !answer.size()) return "0";
    return answer;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cout << solution({3, 30, 33, 300, 3003}) << endl;
    return 0;
}

