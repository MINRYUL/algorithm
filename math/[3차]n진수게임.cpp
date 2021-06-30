#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

string solution(int n, int t, int m, int p) {
    string answer = "", result = "";
    map<int, char> ma;
    ma[10] = 'A'; ma[11] = 'B'; ma[12] = 'C';
    ma[13] = 'D'; ma[14] = 'E'; ma[15] = 'F';
    
    int num = 1; result.push_back('0');
    while(result.size() < t * m){
        int tempNum = num; string s;
        while(tempNum){
            int rest = tempNum % n;
            if(!ma.count(rest)){
                s.push_back((rest) + '0');
            } else{
                char add = ma[rest];
                s.push_back(add);
            }
            tempNum /= n;
        }
        reverse(s.begin(), s.end());
        result.append(s);
        num += 1;
    }
    
    for(int i = p - 1; i < result.size(); i += m){
        if(answer.size() == t) break;
        answer.push_back(result[i]);
    }
    
    return answer;
}
