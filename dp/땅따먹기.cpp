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

int solution(vector<vector<int> > land)
{
    for(int i = 1; i < land.size(); i++){
        for(int j = 0; j < 4; j++){
            int tempNum = 0, pos = -1;
            for(int k = 0; k < 4; k++){
                if(j == k) continue;
                else if(tempNum < land[i - 1][k]){
                    tempNum = land[i - 1][k];
                }
            }
            land[i][j] += tempNum;
        }
    }
    int n = land.size() - 1;
    return max({land[n][0], land[n][1], land[n][2], land[n][3]});
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cout << solution({{1,2,3,5},{5,6,7,100},{4,3,2,1}});
    return 0;
}

