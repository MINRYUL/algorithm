#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <queue>
#include <string>
#include <stack>
#include <map>
#include <queue>

using namespace std;


vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    for(int i = 0; i < arr1.size(); i++){
        vector<int> v;
        for(int j = 0; j < arr2[0].size(); j++){
            int sum = 0;
            for(int k = 0; k < arr2.size(); k++)
                sum += (arr1[i][k] * arr2[k][j]);
            v.push_back(sum);
        }
        answer.push_back(v);
    }
    return answer;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    return 0;
}


