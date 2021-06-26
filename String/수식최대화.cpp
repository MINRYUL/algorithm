#include <string>
#include <vector>
#include <sstream>
#include <stdlib.h>
#include <cstdlib>
#include <map>
#include <cstring>
#include <iostream>

using namespace std;
long long result;
bool sameCalculation;

long long calculation(long long a, long long b, char d){
    if(d == '+') return a + b;
    else if(d == '-') return a - b;
    else return a * b;
}

vector<string> resultExpression(vector<string> expression, char d){
    vector<string> result; int check = 0;
    for(int i = 1; i < expression.size(); i += 2){
        if(expression[i][0] == d && !check){
            check = i + 2;
            long long a = stoll(expression[i - 1]);
            long long b = stoll(expression[i + 1]);
            result.push_back(to_string(calculation(a, b, d)));
        }else{
            if(expression[i][0] == d) sameCalculation = true;
            if(check != i) result.push_back(expression[i - 1]);
            result.push_back(expression[i]);
            if(i == expression.size() - 2)
                result.push_back(expression[i + 1]);
        }
    }
    return result;
}

void backtracking(bool operatorCheck[], vector<char> &operatorSet, int index, string priority, vector<string> &expression){
    if(priority.size() == operatorSet.size()){
        vector<string> temp = expression;
        cout << priority << endl;
        for(int i = 0; i < priority.size(); i++){
            sameCalculation = true;
            while(sameCalculation){
                sameCalculation = false;
                temp = resultExpression(temp, priority[i]);
            }
        }
        
        long long cmpNumber = abs(stoll(temp[0]));
        if(result < cmpNumber) result = cmpNumber;
        return;
    }
    
    for(int i = index; i < operatorSet.size(); i++){
        if(!operatorCheck[i]){
            priority.push_back(operatorSet[i]);
            operatorCheck[i] = true;
            backtracking(operatorCheck, operatorSet, 0, priority, expression);
            priority.pop_back();
            operatorCheck[i] = false;
        }
    }
}

long long solution(string expression) {
    long long answer = 0; result = 0;
    vector<char> operatorSet;
    vector<string> splitExprssion;
    map<char, int> m;
    for(char a : expression){
        if(!m.count(a) && (a < '0' || a > '9')){
            m[a] = 1; operatorSet.push_back(a);
        }
    }
    bool *visited = (bool*)malloc(sizeof(bool) * operatorSet.size());
    memset(visited, false, sizeof(bool) * operatorSet.size());

    string temp;
    for(int i = 0; i < expression.size(); i++){
        if(expression[i] == '-' || expression[i] == '+' || expression[i] == '*'){
            splitExprssion.push_back(temp);
            temp.clear(); temp.push_back(expression[i]);
            splitExprssion.push_back(temp);
            temp.clear();
        } else temp.push_back(expression[i]);
    }
    splitExprssion.push_back(temp);
    backtracking(visited, operatorSet, 0, "", splitExprssion);
    
    return result;
}
